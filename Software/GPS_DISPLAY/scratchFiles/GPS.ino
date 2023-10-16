#include <Adafruit_GPS.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(3, 2);
Adafruit_GPS GPS(&mySerial);

char c;

void setup() {
  Serial.begin(9600);
  GPS.begin(9600);

  GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA);

  GPS.sendCommand(PMTK_SET_NMEA_UPDATE_1HZ);
  delay(1000);
}

void loop() {

  clearGPS();

  while (!GPS.newNMEAreceived()) {
    c = GPS.read();
  }

  GPS.parse(GPS.lastNMEA());
  
  Serial.print("Time: ");
  Serial.print(GPS.hour, DEC); Serial.print(':');
  Serial.print(GPS.minute, DEC); Serial.print(':');
  Serial.print(GPS.seconds, DEC); Serial.print(' ');
  Serial.println();
  Serial.print("Date: ");
  Serial.print(GPS.day, DEC); Serial.print('/');
  Serial.print(GPS.month, DEC); Serial.print("/20");
  Serial.println(GPS.year, DEC);
  Serial.print("Speed (km/h): "); Serial.println(GPS.speed * 1.852); // Speed in km/
  Serial.println();
  Serial.print("Fix: ");Serial.print(GPS.fix);  Serial.println();
  Serial.print("Fix quality: "); Serial.println(GPS.fixquality);
  Serial.print("Satellites: "); Serial.println(GPS.satellites);
  Serial.println();

  Serial.print("Google Maps location: ");
  Serial.print(GPS.latitudeDegrees, 4); Serial.print(", "); Serial.println(GPS.longitudeDegrees, 4);

  Serial.println("-------------------------------------");
  Serial.println();
}

void clearGPS() {
  while (!GPS.newNMEAreceived()) {
    c = GPS.read();
  }
  GPS.parse(GPS.lastNMEA());

  while (!GPS.newNMEAreceived()) {
    c = GPS.read();
  }
  GPS.parse(GPS.lastNMEA());
}
