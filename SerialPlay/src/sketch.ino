
const int pushButton = 2;
const int led = 13;

int buttonState;
int lastButtonState = LOW;

long debounceDelay = 50; // in milliseconds
long lastDebounceTime = 0;

void setup() {
    Serial.begin(9600);
    pinMode(pushButton, INPUT);
    pinMode(led, OUTPUT);

    // is it necessary to set the initial LED state?

}

void loop() {
    int reading = digitalRead(pushButton);
    
    // check if reading matches...if it doesn't then make sure
    // we're not under the debounce delay time
    if (reading != lastButtonState) {
        lastDebounceTime = millis();
    }

    if (millis() - lastDebounceTime > debounceDelay) {
        if (reading != buttonState) {
            // we can change the button state now
            buttonState = reading;
            // only on the down-pressed state
            if (buttonState == HIGH) {
                Serial.println("Button Pressed");
                int ledState = digitalRead(led);
                digitalWrite(led, !ledState);
            }
        }

    }

     lastButtonState = reading;
}
