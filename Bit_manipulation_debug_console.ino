// PROJECT: BIT manipulation debug console logger 
// FILE: Bit_manipulation_debug_console.ino
// DESCRIPTION: Main Arduino sketch for bit manipulation debug console. 
//             Uses serial commands to manipulate bits in a virtual register


#include "bit_ops.h"
#include "command_handler.h"

#define LED_PIN 13                                                // On-board LED pin 13

byte REG_A = 0x00;                                                // Virtual 8-bit register

// Setup function
// Initializes serial communication and configures LED pin
void setup() 
{
    pinMode(LED_PIN, OUTPUT);                                     // Set pinMode
    Serial.begin(9600);                                           // Start serial communication
    Serial.println("=== Bit Manipulation Debug Console ===");
    Serial.println("Commands: SET n | CLEAR n | TOGGLE n | READ");
    Serial.println("---------------------------------------");
}

// Main loop function
// Listens for serial commands and processes them
void loop() 
{
  if (Serial.available())
  {
      String cmd = Serial.readStringUntil('\n');
      cmd.trim();

      handleCommand(cmd, &REG_A);                                 // delegate to handler
      updateLED(LED_PIN, REG_A);                                  // update LED based on REG_A
  }
}



