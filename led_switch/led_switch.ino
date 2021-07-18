#define BUTTON_PIN 2
#define LED_PIN 4

void lightOneLed(int ledPin, bool isOn)
{
    if (isOn) {
        digitalWrite(ledPin, HIGH);
    } else {
        digitalWrite(ledPin, LOW);
    }
}

void blinkOneLed(int ledPin, int count, int frequency = 200)
{
    for (int i = 0; i < count; i++) {
        lightOneLed(ledPin, true);
        delay(frequency);
        lightOneLed(ledPin, false);
        delay(frequency);
    }
}

void initLed(int ledPin, int value = INPUT) {
    pinMode(ledPin, value);
}

int readButtonState(int buttonPin)
{
    int buttonState = readButtonState(buttonPin);

    delay(100);

    return buttonState;
}

void log(int buttonState)
{
    Serial.println(buttonState);
}

void initButton(int buttonPin)
{
    pinMode(buttonPin, INPUT);
}

void handleSwitch(int buttonPin)
{
    int buttonState = readButtonState(buttonPin);
    static int previousState = -1;

    if (buttonState == previousState) {
        return;
    }

    previousState = buttonState;

    log(buttonState);

    lightOneLed(LED_PIN, buttonState);
}

void setup()
{
    Serial.begin(9600);
    initButton(BUTTON_PIN);
    initLed(LED_PIN, OUTPUT);
    Serial.println("Hello world!");
    blinkOneLed(LED_PIN, 3);
}

void loop()
{
    handleSwitch(BUTTON_PIN);
}
