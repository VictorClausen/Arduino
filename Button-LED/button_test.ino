const int buttonPin = 2;    // Pin connected to the button
const int ledPin = 13;      // Pin connected to the LED

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); // Initialize button pin as input with internal pull-up resistor
  pinMode(ledPin, OUTPUT);          // Initialize LED pin as output
}

void loop() {
  int buttonState = digitalRead(buttonPin); // Read the button state

  if (buttonState == HIGH) { // Button is pressed
    digitalWrite(ledPin, LOW); // Turn on LED
  } else {
    digitalWrite(ledPin, HIGH); // Turn off LED
  }
}
