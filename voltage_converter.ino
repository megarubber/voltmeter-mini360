void setup() {
  Serial.begin(9600);
}

void loop() {
  static uint8_t i;
  static const uint8_t size = 255;
  static unsigned convert, voltages[size];
  static unsigned long timer, result;

  for (i = 0, result = 0; i < size - 1; voltages[i] = voltages[i + 1], i++)
    result += voltages[i];
  convert = (result + (voltages[size - 1] = analogRead(A0))) / size;

  if (millis() - timer > 100) {
    timer = millis();
    Serial.print(convert * 5.0 / 1024);
    Serial.flush();
    Serial.println(" V");
  }
}
