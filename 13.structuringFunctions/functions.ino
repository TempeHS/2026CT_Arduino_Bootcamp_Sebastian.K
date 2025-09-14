void OLEDScreen() {
OLED.setFont(u8g2_font_6x12_tf);
OLED.clearDisplay();
OLED.drawStr(0, 10, "vrochaco what");
OLED.nextPage();
}

void PressureSensor() {
  Serial.print("Pressure: ");
  Serial.print(Pressure.readPressure());
  Serial.println("Pa");
}