# BAJA INSTRUMENTATION 23-24

## General Notes
- Will need a budget to be able to fund:
  * Displays (current and new ones)
  * Low Voltage cut off
## Currently working on: 
  We will be able to get ride frequency using a combination of string potentiometers and accelerometers.
    The AutoCad for the fitting of the accelerometer is done.
    The brackets for the potentiometer to sit is also done.
    We will look to test during the christmas break.
  
  Along with that we are looking to get a sponsorship for radios (in-progress)
  Hoping that goes well we will also integrate a headset within the helmet probably just a simple ear piece
## Planned to Implement:
- GPS, Time, Distance - **Done**
- Accelerometer data - (1 Month)
- Implement a Fan for the powertrain (CVT) - (2 weeks)
  * Operated either by temp or battery voltage
  * Voltage can be shown at COMP to express the battery will not die
- Better implementation of 4WD - (1-2 Weeks)
  * On the steering wheel if possible with a fail-safe
- Fuel 
   * Will use time with testing data (2 days)
   * If we have extra time then we will look into other ideas
   * Perhaps a static pressure port from a tee which results in no extension of the fuel line (1 month)
   * Keep in mind gas is different on 2wd and 4wd so if the driver is switching between 2wd and 4wd then time is also extremely inaccurate. 
- Check for wheel speed (2-3 weeks)
- Interaction between driver and team
  * Explore in headset helmets - Contact sponsors
  * Or Connect to a radio with a headset
  * Can also build in macros to send messages from the driver to the team with buttons on the car - however you need signal for this to work

## Sensors Implemented
- Adafruit Ultimate GPS (Absolute positioning @ 10hz)

## Sensors to be Implemented
- MPU6050 Accelerometer (Body and Upright Accelerations)
- SN-04 NPN Inductive sensors (Wheel speeds)

## OTHER IDEAS
- "Sleep mode" to turn itself off
- Measuring Oil temps
- Control the differential, CVT fans, and the brake lights

## NOTES ON PREVIOUS PROGRESS
- GPS, Time, Display (Done Oct 15, 2023)
  * Having issues with the screen and the data displaying
  * Issues resolved around using wrong voltage and incorrect data for the pins
  * Have to re-order new displays \
https://randomnerdtutorials.com/guide-for-oled-display-with-arduino/ \
https://lastminuteengineers.com/adxl335-accelerometer-arduino-tutorial/

UPDATE: Mid-Nov
- Accelerometer via Wifi (ESP32) - There are many issues with the double integration so this is looking less viable and not much progress was made within the last week.
 * Could use a string potentiometer alongside the accelerometer to get displacement without having to double integrate.
 * Double integration is a problem since the shocks will not be moving in a large area thus the magnitude in the error after double integration would give us extremely inaccurate data.
 * String potentiometer is expensive so look into renting a dac from the strain gauge company - get the build in accelerometers too.



