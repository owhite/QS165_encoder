// this was first used to show that the raygun board
// could serve as a bare bones board and talk to the
// AS5048 -- and allowed the results to be sent to the
// onboard OLED. 

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
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

#define LED_PIN PinB4

AS5048A angleSensor(PinC0, true);
Adafruit_SSD1306 display(4);

int led_state = 0;
int level = 0;

void setup() {
     delay(2000);

     pinMode(LED_PIN, OUTPUT);

     angleSensor.begin();
     display.begin(SSD1306_SWITCHCAPVCC, 0x3C); 

     display.clearDisplay();   // clears the screen and buffer
     display.setTextSize(1);
     display.setTextColor(WHITE);
     display.setCursor(0,10 * level);
     display.display();
}

void loop() {
     display.clearDisplay();   // clears the screen and buffer


     display.setCursor(0,10);
     if (led_state) {
       display.print("*  ");
     }
     else {
       display.print("-  ");
     }

     float val = angleSensor.getRotationInDegrees();

     display.println(val);

     display.display();

     led_state =! led_state;
     digitalWrite(LED_PIN, led_state); 

     level++;
     if (level > 99) { level = 0; }
}


