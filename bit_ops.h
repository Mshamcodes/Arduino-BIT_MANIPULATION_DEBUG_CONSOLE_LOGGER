// FILE: bit_ops.h
// DESCRIPTION: Header file for bit manipulation functions.

#ifndef BIT_OPS_H
#define BIT_OPS_H

#include <Arduino.h>

void setBit(byte *reg, int bit);
void clearBit(byte *reg, int bit);
void toggleBit(byte *reg, int bit);
bool getBit(byte reg, int bit);
void updateLED(int ledPin, byte reg);
void printRegister(byte reg);

#endif
