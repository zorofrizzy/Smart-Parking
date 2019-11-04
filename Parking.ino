#include<SoftwareSerial.h>

#include <SPI.h>
#include <Wire.h>

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

SoftwareSerial bt(0,1); //(RX, TX)

//pin definition
const int trigPin1 = 2;
const int trigPin2 = 3;
const int trigPin3 = 4;
const int trigPin4 = 5;
const int trigPin5 = 6;



const int echoPin1 = 8;
const int echoPin2 = 9;
const int echoPin3 = 10;
const int echoPin4 = 11;
const int echoPin5 = 12;

// defines variables


int distance1;
int distance2;
int distance3;
int distance4;
int distance5;


int mydistance(int trigPin, int echoPin)
{
  
  long duration;
  int distance;

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;
  
  return distance;
}



void setup() 
{
  // put your setup code here, to run once:
pinMode(trigPin1, OUTPUT); 
pinMode(trigPin2, OUTPUT); 
pinMode(trigPin3, OUTPUT); 
pinMode(trigPin4, OUTPUT); 
pinMode(trigPin5, OUTPUT); 

pinMode(echoPin1, INPUT);
pinMode(echoPin2, INPUT); 
pinMode(echoPin3, INPUT);
pinMode(echoPin4, INPUT);
pinMode(echoPin5, INPUT);
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();
  delay(2000); // Pause for 2 seconds

  // Clear the buffer
  display.clearDisplay();

 

  // Show the display buffer on the screen. You MUST call display() after
  // drawing commands to make them visible on screen!
  display.display();
  delay(2000);  
Serial.begin(9600);
bt.begin(9600);

Wire.begin();

  // Display static text
  delay(1000);

  }

void loop() {
  // put your main code here, to run repeatedly: 


digitalWrite(trigPin1, LOW);
digitalWrite(trigPin2, LOW);
digitalWrite(trigPin3, LOW);
digitalWrite(trigPin4, LOW);
digitalWrite(trigPin5, LOW);

delayMicroseconds(2);

distance1 = mydistance(trigPin1, echoPin1);
distance2 = mydistance(trigPin2, echoPin2);
distance3 = mydistance(trigPin3, echoPin3);
distance4 = mydistance(trigPin4, echoPin4);
distance5 = mydistance(trigPin5, echoPin5);
int lim = 7;
char d1='0',d2='0',d3='0',d4='0',d5='0';
if(distance1<=lim)
   d1='1';
if(distance2<=lim)
   d2='1';
if(distance3<=lim)
   d3='1';
if(distance4<=lim)
   d4='1';
if(distance5<=lim)
   d5='1';
String bitstream = " ";
bitstream=bitstream+d1+d2+d3+d4+d5; 
Serial.println(bitstream);
    //Serial.println(input); 
    //Print character received on to the serial monitor
    //When connected to a smartphone, one can actually transmit data using this code with ease.

    display.clearDisplay();
int i=50;

  display.setTextSize(1);             // Normal 1:1 pixel scale
  display.setTextColor(WHITE);        // Draw white text
  display.setCursor(5,10);             // Start at top-left corner
  display.println(F("Slot A"));
  display.setCursor(i,10);             // Start at top-left corner
  if(d1=='1')
    display.println(F("Full"));
  else
     display.println(F("Empty"));
  display.setCursor(5,20);             // Start at top-left corner
  display.println(F("Slot B"));
 display.setCursor(i,20);       // Start at top-left corner
  if(d2=='1')
    display.println(F("Full"));
  else
     display.println(F("Empty"));
  display.setCursor(5,30);             // Start at top-left corner
  display.println(F("Slot C"));
  
  display.setCursor(i,30);             // Start at top-left corner
  if(d3=='1')
    display.println(F("Full"));
  else
     display.println(F("Empty"));
  display.setCursor(5,40);             // Start at top-left corner
  display.println(F("Slot D"));
  display.setCursor(i,40);             // Start at top-left corner
  if(d4=='1')
    display.println(F("Full"));
  else
     display.println(F("Empty"));
  display.setCursor(5,50);             // Start at top-left corner
  display.println(F("Slot E"));

  display.setCursor(i,50);             // Start at top-left corner
  if(d5=='1')
    display.println(F("Full"));
  else
     display.println(F("Empty"));
  display.display();

delay(1000);
}
