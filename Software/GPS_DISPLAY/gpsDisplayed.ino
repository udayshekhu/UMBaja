#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GPS.h>

#define SCREEN_WIDTH 128   // OLED display width, in pixels
#define SCREEN_HEIGHT 64   // OLED display height, in pixels

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
Adafruit_GPS GPS(&Serial1);  // Create an Adafruit_GPS instance using hardware serial 1 for communication.

unsigned long displayTime = 3000; // Display "BAJA Team" for 3 seconds initially
unsigned long previousDisplayTime = 0;
bool showBAJATeam = true;
unsigned long startTime = 0; // Track the start time

int textWidth = 6 * 9;  // nice
int textX = (SCREEN_WIDTH - textWidth) / 2;
int textY = (SCREEN_HEIGHT - 8) / 2;

void setup() {
  Serial.begin(9600);
  GPS.begin(9600);

  GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA);
  GPS.sendCommand(PMTK_SET_NMEA_UPDATE_1HZ);
  delay(1000);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    while (1);
  }

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.clearDisplay();
  display.display();
  randomSeed(analogRead(0));

  // Record the start time
  startTime = millis();
}

void loop() {
  clearGPS();

  if (showBAJATeam && millis() - previousDisplayTime < displayTime) {
    // Display "BAJA Team, and check if its 3 seeconds"
    display.clearDisplay();
    display.setCursor(textX, textY);
    display.print("BAJA Team");

    display.display();
  } else {
    // Display GPS data
    unsigned long currentTime = millis();
    if (showBAJATeam) {
      // Transition from "BAJA Team" to GPS data
      previousDisplayTime = currentTime;
      showBAJATeam = false;
      // Reset the start time
      startTime = currentTime;
    }

    while (!GPS.newNMEAreceived()) {
      char c = GPS.read();
    }

    GPS.parse(GPS.lastNMEA());

    display.clearDisplay();

    // Center the speed
    display.setTextSize(4);
    display.setCursor(textX+10, textY-20);
    display.print(GPS.speed * 1.852, 0);
    display.setTextSize(1);
    display.setCursor(textX+40, textY+5);
    display.print("Km/h");

    // Position the time at the bottom left edge
    display.setCursor(0, SCREEN_HEIGHT - 8);
    unsigned long elapsedTime = currentTime - startTime;
    int minutes = elapsedTime / 60000;
    int seconds = (elapsedTime % 60000) / 1000;
    display.print(minutes);
    display.print("m ");
    display.print(seconds);
    display.print("s");

    // Position satellites at the top right
    display.setCursor(SCREEN_WIDTH - 40, SCREEN_HEIGHT - 8);
    display.print("SAT: ");
    display.print(GPS.satellites);

    display.display();
  }
}

void clearGPS() {
  while (!GPS.newNMEAreceived()) {
    char c = GPS.read();
  }
  GPS.parse(GPS.lastNMEA());

  while (!GPS.newNMEAreceived()) {
    char c = GPS.read();
  }
  GPS.parse(GPS.lastNMEA());
}
