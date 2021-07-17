const int ledPin = 2;
const int potentiometerPin = A0;
int potentiometerValue = 0;

void lightALed(int ledPin, bool isOn = true)
{
    if (isOn) {
        digitalWrite(ledPin, HIGH);
    } else {
        digitalWrite(ledPin, LOW);
    }
}

void blinkALed(int ledPin, int waitingTime)
{
    lightALed(ledPin, true);
    delay(waitingTime);
    lightALed(ledPin, false);
    delay(waitingTime);
}

int readPotentiometer(int potentiometerPin)
{
    return analogRead(potentiometerPin); // We get the potentiometer value here
}

void printPotentiometerValue(int potentiometerValue)
{
    static int previousValue = 0;

    if (potentiometerValue == previousValue) {
        return;
    }

    previousValue = potentiometerValue;
    Serial.print("Potentiometer value: ");
    Serial.println(potentiometerValue);
}

int calculateDelay(int potentiometerValue)
{
    // int convertedValue = int (potentiometerValue * 5 / 1024) + 1; // Manual calculation
    int convertedValue = map(potentiometerValue, 0, 1023, 1, 5); // Mapping function

    return 1000 / convertedValue / 2; // Waiting time calculation
}

void setup()
{ 
    Serial.begin(9600);
    pinMode(ledPin, OUTPUT);
}

void loop()
{
    potentiometerValue = readPotentiometer(potentiometerPin);
    printPotentiometerValue(potentiometerValue);
    blinkALed(ledPin, calculateDelay(potentiometerValue));
}