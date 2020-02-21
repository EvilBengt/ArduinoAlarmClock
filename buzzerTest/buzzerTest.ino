const int buttonPin = 3;
const int buzzerPin = 2;

void setup()
{
    pinMode(16, OUTPUT);

    pinMode(buttonPin, INPUT_PULLUP);
    pinMode(buzzerPin, OUTPUT);
}

void loop()
{
    if (digitalRead(buttonPin) == LOW)
    {
        digitalWrite(buzzerPin, HIGH);
    }
    else
    {
        digitalWrite(buzzerPin, LOW);
    }
}
