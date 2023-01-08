// final code to load on the encoder. 
#include <AS5048A.h>

#define PinB0 8
#define PinB1 9
#define PinB2 10
#define PinB3 11
#define PinB4 12
#define PinB5 13

#define PinC0 14
#define PinC1 15
#define PinC2 16
#define PinC3 17
#define PinC4 18
#define PinC5 19

#define PinD0 0
#define PinD1 1
#define PinD2 2
#define PinD3 3
#define PinD4 4
#define PinD5 5
#define PinD6 6
#define PinD7 7

#define POLEPAIRS 7

#define Upin PinC2
#define Vpin PinC1
#define Wpin PinC0

boolean UpinState = true;
int VpinState = LOW;
int WpinState = LOW;

AS5048A angleSensor(PinB1, true);

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
  delay(2000);

  angleSensor.begin();

  pinMode(PinD5,OUTPUT);
  pinMode(Upin,OUTPUT);
  pinMode(Vpin,OUTPUT);
  pinMode(Wpin,OUTPUT);

}

void loop() {
  
  angle = angleSensor.getRotationInDegrees();
  if (test_angle(angle, POLEPAIRS)) { // UpinState = HIGH;
  }
  if (test_angle(angle + 120, POLEPAIRS)) { VpinState = HIGH; }
  if (test_angle(angle + 240, POLEPAIRS)) { WpinState = HIGH; }

  digitalWrite(Upin, UpinState);
  UpinState = !UpinState;
}
void loop2() {
  
  // VpinState = LOW;
  // WpinState = LOW;



  if (test_angle(angle, POLEPAIRS)) { // UpinState = HIGH;
  }
  if (test_angle(angle + 120, POLEPAIRS)) { VpinState = HIGH; }
  if (test_angle(angle + 240, POLEPAIRS)) { WpinState = HIGH; }

  digitalWrite(Upin, UpinState);
  UpinState = !UpinState;

}
