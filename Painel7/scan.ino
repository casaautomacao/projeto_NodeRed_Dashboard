void scanI2C()
{
  byte error, address;
  int nDevices = 0;

  delay(1000);

  Serial.println("Scanning for I2C devices ...");
  for (address = 0x01; address < 0x7f; address++) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
    if (error == 0) {

      if (address >= 0x20 and address <= 0x26) Serial.print("9535 -> ");
      if (address == 0x27) Serial.print("LCD_ -> ");
      if (address == 0x3C) Serial.print("OLED -> ");
      if (address == 0x48) Serial.print("IN_A -> ");
      if (address == 0x51) Serial.print("RTC_ -> ");
      if (address == 0x60 or address == 0x61) Serial.print("OUTA -> ");


      Serial.printf("I2C device found at address 0x%02X\n", address);
      nDevices++;
    } else if (error != 2) {
      Serial.printf("Error %d at address 0x%02X\n", error, address);
    }
  }
  if (nDevices == 0) {
    Serial.println("No I2C devices found");
  }
}
