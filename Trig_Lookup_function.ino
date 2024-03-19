const int tableSize = 91;  // 0 to 90 degrees
const float pi = 3.14159;
float sinTable[tableSize];
float cosTable[tableSize];
float tanTable[tableSize];

void setup() {
    Serial.begin(9600);
  // Generate the lookup table
  for (int i = 0; i < tableSize; i++) {
    float angle = i * pi / 180.0;  // Convert degrees to radians
    sinTable[i] = sin(angle);
    cosTable[i] = cos(angle);
    tanTable[i] = tan(angle);
  }
}

void loop() {
  // Timing analysis for Arduino built-in sin() function
  unsigned long startMillis = millis();
  for (int i = 0; i < 10000; i++) {
    float angle = random(0, 91); // Generate random angle between 0 and 90 degrees
    float sineValue = sin(angle * pi / 180.0);
  }
  unsigned long endMillis = millis();
  Serial.print("Time taken by sin() function: ");
  Serial.print(endMillis - startMillis);
  Serial.println(" ms");

  // Timing analysis for lookupSine() function
  startMillis = millis();
  for (int i = 0; i < 10000; i++) {
    int angle = random(0, 91); // Generate random angle between 0 and 90 degrees
    float sineValue = lookUpSine(angle);
  }
  endMillis = millis();
  Serial.print("Time taken by lookupSine() function: ");
  Serial.print(endMillis - startMillis);
  Serial.println(" ms");

  delay(3000);  // Delay for readability in serial monitor
}

float lookUpSine(int angle) {
  if (angle >= 0 && angle <= 90) {
    return sinTable[angle];
  } else {
    return 0; // If angle is out of range, return 0
  }
}
