ttttttttttttttttttttttttttttttttttttttttttttttttttttttt
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

const char* text = "BAJA Team";
int textWidth = 6 * 9; // Assuming each character is 6 pixels wide
int textX = (SCREEN_WIDTH - textWidth) / 2;
int textY = (SCREEN_HEIGHT - 8) / 2;

const int starCount = 5;    // Number of stars
int starX[starCount];       // X-coordinates for stars
int starY[starCount];       // Y-coordinates for stars
int starSpeed[starCount];   // Falling speed for stars

void setup() {
  Serial.begin(9600);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(1000);
  display.clearDisplay();

  display.setTextSize(1.5);
  display.setTextColor(WHITE);
  display.setCursor(textX, textY);
  display.println(text);
  display.display();

  // Initialize star positions and speeds
  for (int i = 0; i < starCount; i++) {
    starX[i] = random(SCREEN_WIDTH);
    starY[i] = 0;
    starSpeed[i] = random(1, 4); // Adjust the range for different falling speeds
  }
}

void loop() {
  // Clear the display
  display.clearDisplay();

  // Update and draw stars
  for (int i = 0; i < starCount; i++) {
    starY[i] += starSpeed[i];
    
    // If a star reaches the bottom, reset its position
    if (starY[i] > SCREEN_HEIGHT) {
      starX[i] = random(SCREEN_WIDTH);
      starY[i] = 0;
      starSpeed[i] = random(1, 4); // Adjust the range for different falling speeds
    }
    
    // Draw stars
    display.drawPixel(starX[i], starY[i], WHITE);
  }

  // Draw the text
  display.setCursor(textX, textY);
  display.println(text);
  
  // Display everything
  display.display();
}

