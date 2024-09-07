const int BUTTON1_PIN = 2;    // Pin connected to button 1 (ON/OFF)
const int BUTTON2_PIN = 3;    // Pin connected to button 2 (Disp)
const int BUTTON3_PIN = 4;    // Pin connected to button 3 (Vol +)
const int BUTTON4_PIN = 7;    // Pin connected to button 4 (Vol -)
const int BUTTON5_PIN = 10;   // Pin connected to button 5 (Reset)
const int LED1_PIN = 5;       // Pin connected to LED 1 (ON/OFF)
const int LED2_PIN = 6;       // Pin connected to LED 2 (Disp)
const int LED3_PIN = 8;       // Pin connected to LED 3 (Vol +)
const int LED4_PIN = 9;       // Pin connected to LED 4 (Vol -)
const int LED5_PIN = 11;      // Pin connected to LED 5 (Reset)

const unsigned long DEBOUNCE_DELAY = 50; // Debounce delay in milliseconds
const unsigned long LED_ON_DURATION = 1000; // LED on duration (1 second)

struct Button {
  int pin;
  int lastState;
  unsigned long lastDebounceTime;
  bool pressed;
};

Button buttons[] = {
  {BUTTON1_PIN, HIGH, 0, false},
  {BUTTON2_PIN, HIGH, 0, false},
  {BUTTON3_PIN, HIGH, 0, false},
  {BUTTON4_PIN, HIGH, 0, false},
  {BUTTON5_PIN, HIGH, 0, false},
};

void setup() {
  Serial.begin(9600); // Initialize Serial for communication
  for (int i = 0; i < 5; i++) {
    pinMode(buttons[i].pin, INPUT_PULLUP); // Set button pins to input pull-up mode
  }
  pinMode(LED1_PIN, OUTPUT); // Set LED pins to output mode
  pinMode(LED2_PIN, OUTPUT);
  pinMode(LED3_PIN, OUTPUT);
  pinMode(LED4_PIN, OUTPUT);
  pinMode(LED5_PIN, OUTPUT);

  // Ensure all LEDs are off initially
  digitalWrite(LED1_PIN, LOW);
  digitalWrite(LED2_PIN, LOW);
  digitalWrite(LED3_PIN, LOW);
  digitalWrite(LED4_PIN, LOW);
  digitalWrite(LED5_PIN, LOW);
}

void loop() {
  for (int i = 0; i < 5; i++) {
    Button &btn = buttons[i];
    int reading = digitalRead(btn.pin);

    // Check if the button state has changed
    if (reading != btn.lastState) {
      btn.lastDebounceTime = millis(); // Reset debounce timer
    }

    // Check if enough time has passed to consider the button state stable
    if ((millis() - btn.lastDebounceTime) > DEBOUNCE_DELAY) {
      // Check if the button state has changed
      if (reading != btn.pressed) {
        btn.pressed = reading; // Update button state

        if (btn.pressed == LOW) { // Button pressed
          handleButtonPress(i);
        }
      }
    }

    // Save the reading for next comparison
    btn.lastState = reading;
  }

  // Turn off LEDs after their on duration
  checkLEDs();
}

void handleButtonPress(int index) {
  static bool serialState1 = false;
  static int serialState2 = 1;

  switch (index) {
    case 0: // Button 1
      serialState1 = !serialState1;
      Serial.println(serialState1 ? "Test_Room_1_ON" : "Test_Room_1_OFF");
      digitalWrite(LED1_PIN, HIGH);
      delay(LED_ON_DURATION); // Keep LED on for duration
      digitalWrite(LED1_PIN, LOW);
      break;

    case 1: // Button 2
      Serial.print("Test_Room_1_Disp");
      Serial.println(serialState2);
      serialState2 = (serialState2 % 3) + 1; // Cycle through 1, 2, 3
      digitalWrite(LED2_PIN, HIGH);
      delay(LED_ON_DURATION); // Keep LED on for duration
      digitalWrite(LED2_PIN, LOW);
      break;

    case 2: // Button 3 (Vol +)
      Serial.println("Test_Room_1_Vol+");
      digitalWrite(LED3_PIN, HIGH);
      delay(LED_ON_DURATION); // Keep LED on for duration
      digitalWrite(LED3_PIN, LOW);
      break;

    case 3: // Button 4 (Vol -)
      Serial.println("Test_Room_1_Vol-");
      digitalWrite(LED4_PIN, HIGH);
      delay(LED_ON_DURATION); // Keep LED on for duration
      digitalWrite(LED4_PIN, LOW);
      break;

    case 4: // Button 5 (Reset)
      Serial.println("Test_Room_1_RST");
      digitalWrite(LED5_PIN, HIGH);
      delay(LED_ON_DURATION); // Keep LED on for duration
      digitalWrite(LED5_PIN, LOW);
      delay(500); // Additional delay to ensure reset signal is recognized
      asm volatile ("  jmp 0"); // Reset the microcontroller
      break;
  }
}

void checkLEDs() {
  // Ensure LEDs are off after their duration
  for (int i = 0; i < 5; i++) {
    if (digitalRead(buttons[i].pin) == LOW) {
      digitalWrite(LED1_PIN + i, LOW);
    }
  }
}
