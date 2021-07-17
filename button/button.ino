#define BUTTON_PIN 10

void printButtonState(int buttonPin)
{
    boolean buttonState = digitalRead(buttonPin);
    Serial.println(buttonState);
}

void initButton(int buttonPin)
{
    pinMode(buttonPin, INPUT);
}

void setup()
{
    Serial.begin(9600);
    initButton(BUTTON_PIN);
}

void loop()
{
    printButtonState(BUTTON_PIN);
}
