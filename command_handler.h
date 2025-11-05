// FILE: command_handler.h
// DESCRIPTION: Header file for command handler functions.

#ifndef COMMAND_HANDLER_H
#define COMMAND_HANDLER_H

#include <Arduino.h>

void handleCommand(String cmd, byte *reg);
bool isNumber(String s);

#endif
