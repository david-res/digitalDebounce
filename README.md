# DigitalDebounce Library

## Overview
The DigitalDebounce library provides an easy and reliable way to debounce digital inputs in embedded systems, particularly for Arduino-based projects. It is designed to monitor specific bits within bytes, making it ideal for applications where button states or similar digital signals are packed into byte arrays.

## Features
- Debounce individual bits within a byte.
- Flexible initialization with customizable debounce intervals.
- Lightweight and efficient.
- Suitable for single or multiple button debouncing.

## Installation
1. Copy the `digitalDebounce.h` and `digitalDebounce.cpp` files into your Arduino `libraries` directory under a folder named `DigitalDebounce`.
2. Restart your Arduino IDE to recognize the library.

## Usage
### Include the Library
```cpp
#include "digitalDebounce.h"
```

### Create an Instance
To debounce a specific bit within a byte:
```cpp
// Parameters: reference to the byte, bitmask for the bit, debounce interval in ms, initial state
DigitalDebounce button(&byteVariable, 0x01, 50, false);
```
- `&byteVariable`: Pointer to the byte containing the bit to monitor.
- `0x01`: Bitmask for the bit to debounce.
- `50`: Debounce interval in milliseconds.
- `false`: Initial state of the bit (default).

### Check for State Changes
In your `loop()` function, call the `update()` method:
```cpp
if (button.update()) {
    if (button.read()) {
        // Bit is HIGH (pressed)
    } else {
        // Bit is LOW (released)
    }
}
```
- `update()`: Returns `true` if the state has changed.
- `read()`: Returns the current debounced state of the bit.

## Example
Here is a complete example for toggling LEDs based on button presses:
```cpp
#include "digitalDebounce.h"

// Simulated byte array representing input states
byte inputStates[10];

// Create debounce instances
DigitalDebounce button1(&inputStates[5], 0x04, 50, false);
DigitalDebounce button2(&inputStates[6], 0x01, 50, false);

void setup() {
    Serial.begin(9600);
}

void loop() {
    if (button1.update()) {
        if (button1.read()) {
            Serial.println("Button 1 pressed");
        } else {
            Serial.println("Button 1 released");
        }
    }

    if (button2.update()) {
        if (button2.read()) {
            Serial.println("Button 2 pressed");
        } else {
            Serial.println("Button 2 released");
        }
    }
}
```

## Methods
### `DigitalDebounce(const byte* byteRef, byte bitMask, unsigned long interval, bool initialState = false)`
Constructor to initialize a debounce instance.

### `bool update()`
Call this method in the main loop to update the debounce logic. Returns `true` if the state has changed.

### `bool read()`
Returns the current debounced state of the monitored bit.

## License
This library is provided "as-is" without warranty of any kind. You are free to use and modify it for your projects.

