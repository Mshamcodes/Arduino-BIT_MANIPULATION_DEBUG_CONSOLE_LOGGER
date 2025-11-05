# Arduino Bit Manipulation Debug Console

A professional-grade Arduino Uno project demonstrating register-level bit manipulation through a serial command interface.

## 🎯 Features
- Virtual 8-bit register (`REG_A`)
- Serial command interface (`SET`, `CLEAR`, `TOGGLE`, `READ`)
- Built-in input validation and error handling
- Modular C++ firmware design (`bit_ops`, `command_handler`)
- LED reflects bit 0 of the virtual register

## 🧩 Commands
| Command | Description | Example |
|----------|--------------|----------|
| `SET n` | Sets bit `n` | `SET 3` |
| `CLEAR n` | Clears bit `n` | `CLEAR 0` |
| `TOGGLE n` | Toggles bit `n` | `TOGGLE 1` |
| `READ` | Prints the binary value of the register | `READ` |

## ⚙️ Hardware
- Arduino Uno board  
- 1 LED + 220Ω resistor (connected to digital pin 13 or 8)  
- Common GND connection  

## 📘 How to Use
1. Upload the code to your Arduino Uno  
2. Open the Serial Monitor (9600 baud)  
3. Enter commands like:
