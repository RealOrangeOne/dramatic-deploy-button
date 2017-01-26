#include <Arduino.h>


#define READ_PIN 9
#define KEY_TO_PRESS KEY_RETURN
#define REPEAT_DELAY 1000
#define LED_BUILTIN 13


bool isDepressed = false;


void handleInput() {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(REPEAT_DELAY);
    digitalWrite(LED_BUILTIN, LOW);
}


void setup() {
    pinMode(READ_PIN, INPUT_PULLUP);
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(9600);
}


void loop() {
    if (digitalRead(READ_PIN) == LOW && !isDepressed) {
        isDepressed = true;
        handleInput();
    }

    else if (digitalRead(READ_PIN) == HIGH && isDepressed) {
        isDepressed = false;
    }
}
