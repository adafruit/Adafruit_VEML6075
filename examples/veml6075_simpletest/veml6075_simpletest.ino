/*!
 * @file veml6075_simple.ino
 *
 * A basic test of the sensor with default settings
 * 
 * Designed specifically to work with the VEML6075 sensor from Adafruit
 * ----> https://www.adafruit.com/products/3964
 *
 * These sensors use I2C to communicate, 2 pins (SCL+SDA) are required
 * to interface with the breakout.
 *
 * Adafruit invests time and resources providing this open source code,
 * please support Adafruit and open-source hardware by purchasing
 * products from Adafruit!
 *
 * Written by Limor Fried/Ladyada for Adafruit Industries.  
 *
 * MIT license, all text here must be included in any redistribution.
 *
 */
 
#include <Wire.h>
#include "Adafruit_VEML6075.h"

Adafruit_VEML6075 uv = Adafruit_VEML6075();

void setup() {
  Serial.begin(115200);
  while (!Serial) { delay(10); }
  Serial.println("VEML6075 Simple Test");

  if (! uv.begin()) {
    Serial.println("Failed to communicate with VEML6075 sensor, check wiring?");
    while (1) { delay(100); }
  }
  Serial.println("Found VEML6075 sensor");
}


void loop() {
  Serial.print("UV Index reading: "); Serial.println(uv.readUVI());
  delay(1000);
}
