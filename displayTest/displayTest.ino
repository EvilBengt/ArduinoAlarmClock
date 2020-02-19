#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup()
{
    lcd.begin(20, 4);
    lcd.clear();
    lcd.printstr("Hurr Durr");
}

void loop()
{

}
