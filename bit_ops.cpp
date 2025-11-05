// FILE: bit_ops.cpp
// DESCRIPTION: Implementation of bit manipulation functions for virtual register.
//             Functions to set, clear, toggle, and read bits, as well as update an LED

#include "bit_ops.h"

// SetBit function
void setBit(byte *reg, int bit) 
{
    *reg |= (1 << bit);
    Serial.print("Bit "); Serial.print(bit); Serial.println(" set.");
}

// ClearBit function
void clearBit(byte *reg, int bit) 
{
    *reg &= ~(1 << bit);
    Serial.print("Bit "); Serial.print(bit); Serial.println(" cleared.");
}

// Toggle function
void toggleBit(byte *reg, int bit) 
{
    *reg ^= (1 << bit);
    Serial.print("Bit "); Serial.print(bit); Serial.println(" toggled.");
}

// GetBit function
bool getBit(byte reg, int bit) 
{
    return (reg >> bit) & 1;
}

// UpdateLED function
void updateLED(int ledPin, byte reg) 
{
    digitalWrite(ledPin, getBit(reg, 0) ? HIGH : LOW);
}

// Print the register value function
void printRegister(byte reg) 
{
    Serial.print("REG_A: ");
    for (int i = 7; i >= 0; i--) 
    {
        Serial.print((reg >> i) & 1);
    }
    Serial.println();
}
