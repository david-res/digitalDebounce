#ifndef digitalBounce_h
#define digitalBounce_h

#include "Arduino.h"

// Class definition for debouncing a button bit in a byte
class digitalDebounce {
private:
    const byte* bytePtr;           // Pointer to the byte being monitored
    byte mask;                     // Mask to isolate the specific bit
    bool lastState;                // Last stable state of the button
    bool defaultState;             // Default state of the button
    unsigned long lastToggleTime;  // Time of last state change
    unsigned long debounceInterval; // Debounce time

public:
    // Constructor: Initializes the byte reference, mask, debounce interval, and default state
    digitalDebounce(const byte* byteReference, byte bitMask, unsigned long interval, bool initialState = false);

    // Update the debounce logic and return true if the state changes
    bool update();

    // Get the current debounced state
    bool read() const;
};

#endif
