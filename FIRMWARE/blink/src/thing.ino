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

#define LED2 PinD5
#define Upin PinC2

boolean led_state = false;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED2, OUTPUT);
  pinMode(Upin, OUTPUT);
  DDRD = B11111111; // set PORTD (digital 7~0) to outputs
  DDRD = B00100000; // set PORTD (digital 7~0) to outputs
}

void loop(){
  PORTD = B00100000; // digital 4~7 HIGH, digital 3~0 LOW
  PORTD = B00000000; // 
}

void loop2() {
  digitalWrite(LED2, led_state);
  digitalWrite(Upin, led_state);
  // delay(1);                
  led_state = !led_state;
}
