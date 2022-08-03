
#include <SPI.h>
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



void setup() { 
  Control_Surface.begin();
  Wire.begin(0,4);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  // text display tests
  display.clearDisplay();
  display.setTextSize(2);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setCursor(25,0);             // Start at top-left corner
  display.println(F("CChange"));
  display.setCursor(12,25); 
  display.print("BLE_MIDI");
  display.setCursor(12,40); 
  display.print("Control");   
  display.display();
  }

void loop() { Control_Surface.loop(); }
