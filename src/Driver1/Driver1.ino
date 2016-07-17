// connect Pin 6 to SIG on FET board;  VCC=5V and GND, also.
#define DRIVE 6

// connected to a linear pot  
#define SLIDE 0

// the FET board needs a flyback diode across V+ and V- to control 
// negative voltage deviations.

// my Asco 8202 G002 draws 0.85A @ 24V at full tilt

void setup() {
  Serial.begin(115200);
  
  // output
  pinMode(DRIVE, OUTPUT);
  
  // input
  pinMode(SLIDE, INPUT);
}

void loop() {
  delay(100);

  word reading = analogRead(SLIDE);
  byte mappedReading = map(reading, 0, 1023, 0, 255);
  
  Serial.print("Reading: ");
  Serial.print(reading);
  Serial.print("\tMapped reading: ");
  Serial.print(mappedReading);
  Serial.println();

  analogWrite(DRIVE, mappedReading);
}
