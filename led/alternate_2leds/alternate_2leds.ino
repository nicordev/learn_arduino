int ledPinBlue = 3;
int ledPinRed = 4;
int isOn = true;

void lightALed(int ledPin, bool isOn)
{
    if (isOn) {
        digitalWrite(ledPin, HIGH);
    } else {
        digitalWrite(ledPin, LOW);
    }
}

void setup()
{
    pinMode(ledPinBlue, OUTPUT);
    pinMode(ledPinRed, OUTPUT);
}

void loop()
{
    lightALed(ledPinBlue, isOn);
    lightALed(ledPinRed, !isOn);

    delay(2000);
    isOn = !isOn;
}
