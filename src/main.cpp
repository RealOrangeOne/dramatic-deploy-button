#include <Arduino.h>


#define READ_PIN 9
#define KEY_TO_PRESS KEY_RETURN
#define REPEAT_DELAY 1000


bool isHigh = false;


void handleInput() {
    Serial.println('Handled!');
    delay(REPEAT_DELAY);
}


void setup() {
    pinMode(READ_PIN, INPUT_PULLUP);
    Serial.begin(9600);
}


void loop() {
    if (digitalRead(READ_PIN) == HIGH && !isHigh) {
        isHigh = true;
        handleInput();
    }

    if (digitalRead(READ_PIN) == LOW && isHigh) {
        isHigh = false;
    }
}
