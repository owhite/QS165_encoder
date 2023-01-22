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


// AS5048A angleSensor(PinB1, true);
AS5048A angleSensor(10, false);

int led_state = 0;
int count = 0;
void setup() {
  delay(100);

  pinMode(13,OUTPUT);

  angleSensor.begin();

  Serial.begin(9600);
}

void loop() {

  led_state =! led_state;

  float val = angleSensor.getRotationInDegrees();
  delay(100);
  Serial.println(val);

  int x = int(val);
  // analogWrite(PinD5, map(x, 0, 360, 0, 255));
  // analogWrite(PinD5, int(val));
}
