# Church Keypad Controller

## Overview

This project is a keypad controller designed for St. Mena and St. Marina Hallam Church. It is based on an Arduino Nano and is intended to help teachers control the TVs in the church hall without interfering with the AV team's equipment. The keypad allows teachers to perform several functions, including turning displays on and off, changing display modes, and adjusting the volume.

## Features

- **Display Control:** Toggle TV displays on and off and cycle through different display modes.
- **Volume Adjustment:** Increase or decrease the volume of the TV.
- **System Reset:** Reset the system with a single button press.

## Components

- **Arduino Nano:** The microcontroller that manages the keypad inputs and outputs.
- **Keypad Buttons:** 
  - Button 1: Toggle TV display on/off
  - Button 2: Cycle through display modes (Disp1, Disp2, Disp3)
  - Button 3: Increase volume
  - Button 4: Decrease volume
  - Button 5: Reset the system
- **LED Indicators:**
  - LED 1: Indicates button 1 action
  - LED 2: Indicates button 2 action
  - LED 3: Indicates button 3 action
  - LED 4: Indicates button 4 action
  - LED 5: Indicates button 5 action


## Code

The code for the keypad controller can be found in the `main.ino` file. It handles the button debouncing, state management, and serial communication to perform the following actions:

- **Button 1:** Toggles the TV display on and off.
- **Button 2:** Cycles through display modes: "Disp1", "Disp2", and "Disp3".
- **Button 3:** Increases the volume.
- **Button 4:** Decreases the volume.
- **Button 5:** Resets the system.

## Installation

1. **Hardware Setup:**
   - Connect the buttons and LEDs to the Arduino Nano according to the wiring diagram.

2. **Software Setup:**
   - Upload the code from the `main.ino` file to the Arduino Nano using the Arduino IDE.

3. **Testing:**
   - Verify that each button performs its respective function and that the LEDs respond correctly.

## Usage

1. Press **Button 1** to turn the TV display on or off.
2. Press **Button 2** to cycle through the display modes.
3. Press **Button 3** to increase the volume.
4. Press **Button 4** to decrease the volume.
5. Press **Button 5** to reset the system.

## Contact

For any questions or issues, please contact the AV team at St. Mena and St. Marina Hallam Church.

---

Thank you for using the Church Keypad Controller! We hope this tool makes managing the AV equipment easier and more efficient.


