const int pirPins[] = {2, 3, 4, 5, 6};
const int buttonPins[] = {12, 13, A0, A1, A2};
const int ledPins[] = {7, 8, 9, 10, 11};
const int numSensors = 5;

const int dataPin = A4;
const int clockPin = A5;
const int latchPin = A3;

bool sensorEnabled[numSensors] = {false};
bool pirDetected[numSensors] = {false};

int pirDetCount;

const byte liczby[6] = {63, 121, 36, 48, 25, 18};

void setup() {
  for (int i = 0; i < numSensors; i++) {
    pinMode(pirPins[i], INPUT);
    pinMode(buttonPins[i], INPUT_PULLUP);
    pinMode(ledPins[i], OUTPUT);
  }

  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  for (int i = 0; i < numSensors; i++) {
    if (digitalRead(buttonPins[i]) == LOW) { 
      sensorEnabled[i] = !sensorEnabled[i];
      pirDetected[i] = false;
      delay(300);
    }
  }

  bool anySensorActive = false;
  pirDetCount = 0;
  
  for (int i = 0; i < numSensors; i++) {
    if (sensorEnabled[i]) {
      anySensorActive = true;
      if (digitalRead(pirPins[i]) == HIGH) {
        pirDetected[i] = true;
      }
      if (pirDetected[i]) {
        Serial.print("Czujnik ");
        Serial.print(i + 1);
        Serial.println(" wykryl ruch!");
        pirDetCount++;
      }
    }
  }

  for (int i = 0; i < numSensors; i++) {
    digitalWrite(ledPins[i], !sensorEnabled[i]);
  }
  
  if ((pirDetCount > 0) && (pirDetCount <= 5)) {
    writeLED(liczby[pirDetCount]);
  } else {
    writeLED(anySensorActive ? 254 : 247);
  }
}

void writeLED(byte data) {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, data);
  digitalWrite(latchPin, HIGH);
}
