// FILE: command_handler.cpp
// DESCRIPTION: Implementation of command handler for bit manipulation debug console.


#include "command_handler.h"
#include "bit_ops.h"


// HandleCommand function
// Parses and executes commands to manipulate bits in the register
// Commands: SET n | CLEAR n | TOGGLE n | READ
void handleCommand(String cmd, byte *reg) 
{
    if (cmd.startsWith("SET")) 
    {
      String arg = cmd.substring(3); arg.trim();
      if (arg.length() == 0) { Serial.println("Error: Missing bit index for SET"); return; }
      if (!isNumber(arg)) { Serial.println("Error: Invalid bit index for SET"); return; }

      int bit = arg.toInt();
      if (bit < 0 || bit > 7) { Serial.println("Error: Bit index must be 0–7"); return; }

      setBit(reg, bit);
    }
    else if (cmd.startsWith("CLEAR")) 
    {
      String arg = cmd.substring(5); arg.trim();
      if (arg.length() == 0) { Serial.println("Error: Missing bit index for CLEAR"); return; }
      if (!isNumber(arg)) { Serial.println("Error: Invalid bit index for CLEAR"); return; }

      int bit = arg.toInt();
      if (bit < 0 || bit > 7) { Serial.println("Error: Bit index must be 0–7"); return; }

      clearBit(reg, bit);
    }
    else if (cmd.startsWith("TOGGLE")) 
    {
      String arg = cmd.substring(6); arg.trim();
      if (arg.length() == 0) { Serial.println("Error: Missing bit index for TOGGLE"); return; }
      if (!isNumber(arg)) { Serial.println("Error: Invalid bit index for TOGGLE"); return; }

      int bit = arg.toInt();
      if (bit < 0 || bit > 7) { Serial.println("Error: Bit index must be 0–7"); return; }

      toggleBit(reg, bit);
    }
    else if (cmd.equalsIgnoreCase("READ")) 
    {
      printRegister(*reg);
    }
    else if (cmd.length() > 0) 
    {
      Serial.println("Invalid command! Use: SET n | CLEAR n | TOGGLE n | READ");
    }
}


// Function to check if a string represents a valid number
bool isNumber(String s) 
{
  for (unsigned int i = 0; i < s.length(); i++) 
  {
      if (!isDigit(s.charAt(i))) 
      {
        return false;
      }
  }
  return true;
}
