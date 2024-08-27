const int buttonPin = 2;    // Pin connected to the button
const int ledPins[] = {8, 9, 10}; // Pins connected to the LEDs
int lastLED = -1;            // Track the last LED that was lit up

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); // Initialize button pin as input with internal pull-up resistor
  
  // Initialize all LED pins as outputs
  for (int i = 0; i < 3; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW); // Make sure all LEDs are off initially
  }
}

void loop() {
  int buttonState = digitalRead(buttonPin); // Read the button state

  if (buttonState == LOW) { // Button is pressed
    delay(50); // Debounce delay
    while (digitalRead(buttonPin) == LOW); // Wait for button release

    if (lastLED != -1) {
      digitalWrite(ledPins[lastLED], LOW); // Turn off the previous LED
    }

    // Choose a random LED to turn on
    int randomLED = random(0, 3);
    digitalWrite(ledPins[randomLED], HIGH);
    
    lastLED = randomLED; // Update lastLED to the current LED
  }
}
