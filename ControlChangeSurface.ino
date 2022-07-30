#include <Control_Surface.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h> //https://github.com/adafruit/Adafruit_SSD1306

BluetoothMIDI_Interface midi;

CCButtonLatched button1 {32, 65}; // {pin №, CC №}
CCButtonLatched button2 {33, 66}; // {pin №, CC №}
CCButtonLatched button3 {25, 67}; // {pin №, CC №}
CCButtonLatched button4 {26, 68}; // {pin №, CC №}
CCButtonLatched button5 {27, 69}; // {pin №, CC №}
//CCButtonLatched button6 {17, 70}; // {pin №, CC №}
//CCButtonLatched button7 {16, 71}; // {pin №, CC №}
//CCButtonLatched button8 {4, 72}; // {pin №, CC №}

// OLED Screen config
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
//Adafruit_SSD1306 display(0x3c, 15, 2)
//Wire.begin(0,4);
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


//void displayMessage() {
//  // Clear the buffer
//  display.clearDisplay();
//// display.setTextSize(fontSize);
//  display.setCursor(0, 0);
////  display.print(message);
//  display.display(); // actually display all of the above
//}

void initDisplay() {
  Serial.println("Init display");
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }
  // Clear the buffer
  display.clearDisplay();  //Clear the buffer first so we don't see Adafruit splash
  display.display();
  display.setTextColor(SSD1306_WHITE);
  display.print("Control Surface");
}


void setup() { 
  Control_Surface.begin();
  Wire.begin(0,4);
  initDisplay();
  }

void loop() { Control_Surface.loop(); }
