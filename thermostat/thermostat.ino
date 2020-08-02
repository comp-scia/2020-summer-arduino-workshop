/*
* Required Libraries:
* - "LiquidCrystal" : Standard Arduino Library
* - "DHT Sensor Library" : https://github.com/adafruit/DHT-sensor-library
*/
#include <LiquidCrystal.h>
#include <DHT.h>
#include <DHT_U.h>
  
// DHT-11 Temperature and Humidity Sensor
#define DHTPIN 13
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// LCD Display (PIN)(LCD1602 Module)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const String TEMP_STR = "Temp(F): ";
const String HUMID_STR = "Humid: ";

void setup() {
    // Serial Monitor
    Serial.begin(9600);
    // LCD Display
    lcd.begin(16, 2);
    for(int i = 0; i <= 3; i += 1) { 
        lcd.clear();
        lcd.setCursor(i, 0);
        lcd.print("Welcome to");
        delay(150);
    }
    lcd.setCursor(1,1);
    lcd.print("Thermostat 1.0"); 

    delay(5000);
    lcd.clear();

    dht.begin();

    // LCD Display (Temp and Humidity)
    lcd.setCursor(0,0);
    lcd.print(TEMP_STR);
    lcd.setCursor(0,1);
    lcd.print(HUMID_STR);
    delay(1500);
}


void loop() {
    // Farenheit Temp and Humidity
    float fTemp = dht.readTemperature(true);
    float humid = dht.readHumidity();

    if (isnan(humid) && fTemp) {
        lcd.clear();
        lcd.setCursor(4,0);
        lcd.print("!SENSOR!");
        lcd.setCursor(5,1);
        lcd.print("!ERROR!"); 
        delay(1000);
        return;
    }
    // LCD Display (Temp and Humidity)
    lcd.setCursor(0,0);
    lcd.print(TEMP_STR);
    lcd.print(fTemp);
    lcd.setCursor(0,1);
    lcd.print(HUMID_STR);
    lcd.print(humid);

    delay(100);
}
