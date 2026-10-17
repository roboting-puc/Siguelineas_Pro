#pragma once
#include <Arduino.h>

//Macros
#define rep(i, n) for(int i=0; i<n; i++)
#define DBG_MODE true

//==================== <Pines> ===========================

//------- Peripherals ----------
#define BUTTON_PIN_A 18
#define BUTTON_PIN_B 19

const int buttonPins[2] = {BUTTON_PIN_B, BUTTON_PIN_A};
#define A 0
#define B 1


#define POWER_LED_PIN 21 
#define MODE_LED_PIN 22
#define STATUS_LED_PIN 23

const int ledPins[3] = {POWER_LED_PIN, MODE_LED_PIN, STATUS_LED_PIN};
#define POWER_LED 0
#define MODE_LED 1
#define STATUS_LED 2


//------- Motors ----------
//Izq
# define AIN1 17
# define AIN2 16

//Der
# define BIN1 14
# define BIN2 13

//Turbine
#define TURBINE_PIN 15

//------- IR Sensors ----------

#define SENSOR_COUNT 8
const int sensorCentralPins[SENSOR_COUNT] = {36, 39, 34, 35, 32, 33, 25, 26};
const double weights[SENSOR_COUNT] = {-3.5, -2.5, -1.5, -0.5, 0.5, 1.5, 2.5, 3.5};

#define LEFT_PIN 27
#define RIGHT_PIN 4

#define LEFT_IDX SENSOR_COUNT
#define RIGHT_IDX SENSOR_COUNT+1

#define LEFT_THRESHOLD 0.4
#define RIGHT_THRESHOLD 0.6

//Pin manager
const int INPUT_PINS[] = {};
const int OUTPUT_PINS[] = {POWER_LED_PIN, MODE_LED_PIN, STATUS_LED_PIN};

const int N_INPUT = sizeof(INPUT_PINS)/sizeof(int);
const int N_OUTPUT = sizeof(OUTPUT_PINS)/sizeof(int);


//------- Code ----------

void init_pins(){
  pinMode(BUTTON_PIN_A, INPUT_PULLUP);
  pinMode(BUTTON_PIN_B, INPUT_PULLUP);

  rep(i, N_OUTPUT)
    pinMode(OUTPUT_PINS[i], OUTPUT);

  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(TURBINE_PIN, OUTPUT);

  // ledcSetup(0, 20000, 8);
  // ledcSetup(1, 20000, 8);
  // ledcSetup(2, 20000, 8); 
  // ledcSetup(3, 20000, 8); 
  // ledcSetup(4, 20000, 8); 

  // ledcAttachPin(AIN1, 0); 
  // ledcAttachPin(AIN2, 1);
  // ledcAttachPin(BIN1, 2);
  // ledcAttachPin(BIN2, 3);
  // ledcAttachPin(TURBINE_PIN, 4);
}


void WaitBoton(int button){
  if(DBG_MODE){
    Serial.println("\nWaiting button " + String(button) + "\n");
  }
  
  delay(500);

  while(digitalRead(buttonPins[button])){}
}


void setLed(int led, bool on){
    if(DBG_MODE){
      Serial.println("\nSet LED " + String(led) + "to val: " + String(on) + "\n");
    }
    
    digitalWrite(ledPins[led], on);
}