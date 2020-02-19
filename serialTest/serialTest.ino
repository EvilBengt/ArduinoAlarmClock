int counter = 0;

void setup()
{
    Serial.begin(9600);
    Serial.println("TEST");
}

void loop()
{
    Serial.println(counter);
    counter++;
    delay(500);
}
