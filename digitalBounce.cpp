#include "digitalBounce.h"

// Constructor: Initialize the byte reference, mask, debounce interval, and default state
digitalDebounce::digitalDebounce(const byte* byteReference, byte bitMask, unsigned long interval, bool initialState)
    : bytePtr(byteReference), mask(bitMask), lastState(initialState), defaultState(initialState), 
      lastToggleTime(0), debounceInterval(interval) {}

// Update the debounce logic and return true if the state changes
bool digitalDebounce::update() {
    bool currentState = (*bytePtr & mask) != 0; // Get the current state of the bit
    unsigned long currentTime = millis();

    // Only consider the state change if enough time has passed (debounce interval)
    if (currentState != lastState && (currentTime - lastToggleTime >= debounceInterval)) {
        lastToggleTime = currentTime;
        lastState = currentState;
        return true; // State has changed
    }

    return false; // No change or within debounce interval
}

// Get the current debounced state
bool digitalDebounce::read() const {
    return lastState;
}
