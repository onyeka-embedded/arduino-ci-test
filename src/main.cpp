#include <Arduino.h>
#include <LiquidCrystal.h> // Include LiquidCrystal Library
#include <dht.h>

#define outPin 10

LiquidCrystal lcd(9, 8, 7, 6, 5, 4); /* Create an LCD object. */
dht DHT;							 

void setup()
{
	lcd.begin(16, 2); // Initialize the LCD
	DHT.read11(outPin);

	lcd.setCursor(2, 0);
	lcd.print("Embedded/IoT");
	lcd.setCursor(2, 1);
	lcd.print("Stem Shield");
	delay(4000);
	lcd.clear()
}

void loop()
{

	float t = DHT.temperature;
	float h = DHT.humidity;

	lcd.setCursor(0, 0);
	lcd.print("Temp:");
	lcd.print(t, 0);
	lcd.print((char)223); // shows degrees character
	lcd.print("C");

	lcd.setCursor(0, 1);
	lcd.print("Hum:");
	lcd.print(h, 0);
	lcd.print("%");

	lcd.setCursor(12, 1);
	lcd.print("demo");

	delay(2000);
}
