#include <DS3231Device.h>
#include <Wire.h>

// Declare DS3231Device object and DeviceTime struct
DeviceTime timetortc;
DS3231Device Device;

void setup() {
  // Start Serial and I2C Bus
  Serial.begin(9600);
  Wire.begin();

  // Format: Second, Minute, Hour
  // in this example the time on the DS3231 is set to 20:49:00
  timetortc = {byte(0), byte(49), byte(20)};

  // Setting time
  Device.setTime(timetortc);

}

void loop() {
  // put your main code here, to run repeatedly:

}
