#include <Arduino.h>

#include <CAN.h>
#include <FastLED.h>
#include <LiquidCrystal_I2C.h>
#include <OBD2.h>
#include <Wire.h>

#define LedPin 3
#define buttonPin 7

#define LONG_PRESS_TIME 1000
#define BLINK_DURATION 50
#define BLINK_RPM 2500

#define NUM_LEDS 15

bool lastState = false;
bool currentState = false;
bool isPressing = false;
bool isLongDetected = false;
unsigned long pressedTime = 0;
unsigned long releasedTime = 0;

bool colorsAreTurnedOn = true;
unsigned long ledBlinkPeriod = 0;

int preset = 2;
int numberOfPresets = 3;
bool displayIsOn = true;
bool ledIsOn = true;

byte Heart[8] = {0b00000, 0b01010, 0b11111, 0b11111,
                 0b11111, 0b01110, 0b00100, 0b00000};

byte Degree[8] = {0b01100, 0b10010, 0b10010, 0b01100,
                  0b00000, 0b00000, 0b00000, 0b00000};

void intro();
void ledsLoop();
void enableDisplayAndLED(bool turnOn);
void shortPressed();
void longPressed();
void checkOBD();
void buttonListener();
void printDataToScreen();
void printRPM(int column, int row);
void printValue(String title, int pid, bool printUnits, bool isFloat,
                int column, int row);
void printTemp(String title, int pid, int column, int row);
