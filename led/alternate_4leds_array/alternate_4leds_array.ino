const int ledPinBlue = 3;
const int ledPinRed = 4;
const int ledPinGreen = 7;
const int ledPinYellow = 10;
const int ledCount = 4;

int ledPins[4] = {
    ledPinBlue,
    ledPinRed,
    ledPinGreen,
    ledPinYellow
};

void lightALed(int ledPin, bool isOn)
{
    if (isOn) {
        digitalWrite(ledPin, HIGH);
    } else {
        digitalWrite(ledPin, LOW);
    }
}

void initLedPin(int ledPin, int value) {
    pinMode(ledPin, value);
}

void turnOffLights() {
    for (int i = 0; i < ledCount; i++) {
        lightALed(ledPins[i], false);
    }
}

void lightOnlyALed(int ledPin) {
    int isLedOn = true;

    turnOffLights();

    for (int i = 0; i < 5; i++) {
        lightALed(ledPin, isLedOn);
        isLedOn = !isLedOn;
        delay(200);
    }
}

void lightEachLed() {
    for (int j = 0; j < ledCount; j++) {
        lightOnlyALed(ledPins[j]);
    }
}

void setup()
{
    for (int i = 0; i < ledCount; i++) {
        initLedPin(ledPins[i], OUTPUT);
    }
}

void loop()
{
    lightEachLed();
}
