#include <DS3231Device.h>
#include <Wire.h>

// Declare DS3231Device object and DeviceTime struct
DeviceTime timefromrtc;
DS3231Device Device;

void setup() {
  // Start Serial and Wire for I2C
  Serial.begin(9600);
  Wire.begin();

}

void loop() {
  // Get Time every second
  delay(1000);
  timefromrtc = Device.getTime();

  Serial.print(timefromrtc.Heure);
  Serial.print(":");
  Serial.print(timefromrtc.Minute);
  Serial.print(":");
  Serial.println(timefromrtc.Seconde);

  Serial.print("Date : ");
  Serial.print(timefromrtc.JSemaine);
  Serial.print(" ");
  Serial.println(timefromrtc.Date);
}
