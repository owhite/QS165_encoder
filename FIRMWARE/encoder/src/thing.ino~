// test the math and display values from an UNO into the serial plotter. 


#define POLEPAIRS 7

float angle = 0.00000;
float inc = 1.0;
int count = 0;

boolean test_angle(float a, float polepairs) {
  boolean r = false;

  float sin_result = sin((a * polepairs) * (M_PI / 180));

  if (sin_result - 0.0 >= 0.0001) {
    r = true;
  }

  return(r);
}

void setup() {
  Serial.begin(115200);
  while (! Serial);
  Serial.println("Min:-2,Max:4");
}

void loop() {
  
  if (angle - 360.0 >= 0.0001) {
    Serial.print("Idx:1.4, ");
    angle = 0.0;
  }
  else {
    Serial.print("Idx:-1.4, ");
  }

  if (test_angle(angle, POLEPAIRS)) {
    Serial.print("U:1, ");
  }
  else {
    Serial.print("U:0, ");
  }
  if (test_angle(angle + 120, POLEPAIRS)) {
    Serial.print("V:2, ");
  }
  else {
    Serial.print("V:1.1, ");
  }

  if (test_angle(angle + 240, POLEPAIRS)) {
    Serial.print("W:3.0, ");
  }
  else {
    Serial.print("W:2.1, ");
  }

  Serial.print("Phase:");
  Serial.println(sin((angle * POLEPAIRS) * (M_PI / 180)));
  angle = angle + inc;

  delay(10);
}
