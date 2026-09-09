#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// -------------------- LCD --------------------
LiquidCrystal_I2C lcd(0x27, 16, 2);

// -------------------- DHT11 --------------------
#define DHTPIN 7
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

// -------------------- Pin Definitions --------------------
#define CO_SENSOR A0
#define AQI_SENSOR A1
#define GAS_SENSOR A2

#define BUZZER 11
#define GREEN_LED 10
#define RED_LED 9

// -------------------- Setup --------------------
void setup()
{
  Serial.begin(9600);

  pinMode(CO_SENSOR, INPUT);
  pinMode(AQI_SENSOR, INPUT);
  pinMode(GAS_SENSOR, INPUT);

  pinMode(BUZZER, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  lcd.init();
  lcd.backlight();

  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(RED_LED, HIGH);

  dht.begin();

  // Welcome message
  lcd.setCursor(0, 0);
  lcd.print(" Air Quality ");

  lcd.setCursor(0, 1);
  lcd.print(" Monitoring ");

  Serial.println("Air Quality Monitoring System");

  delay(3000);

  lcd.clear();
}

// -------------------- Main Loop --------------------
void loop()
{
  // Read DHT11 values
  float h = dht.readHumidity();
  int t = dht.readTemperature();

  // Read sensor values
  int a = analogRead(CO_SENSOR);
  int b = analogRead(AQI_SENSOR);
  int c = analogRead(GAS_SENSOR);

  // -------------------- Temperature --------------------
  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(t);
  lcd.print(char(223));
  lcd.print("C");

  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" C");

  // -------------------- Humidity --------------------
  lcd.setCursor(8, 0);
  lcd.print("H:");
  lcd.print(h);
  lcd.print("%");

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.println(" %");

  delay(150);

  // -------------------- CO --------------------
  lcd.setCursor(0, 1);
  lcd.print("CO:");
  lcd.print(a / 2);
  lcd.print(" ");

  Serial.print("CO: ");
  Serial.println(a / 2);

  // -------------------- AQI --------------------
  lcd.setCursor(8, 1);
  lcd.print("AQI:");
  lcd.print(b / 2);
  lcd.print(" ");

  Serial.print("AQI: ");
  Serial.println(b / 2);

  delay(1500);

  // -------------------- High CO Alert --------------------
  if (a / 2 > 100)
  {
    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("High CO...");

    digitalWrite(BUZZER, HIGH);
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED, LOW);

    delay(500);

    digitalWrite(BUZZER, LOW);

    delay(500);

    lcd.clear();
  }

  // -------------------- High Temperature Alert --------------------
  else if (t > 35)
  {
    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("High Temperature");

    digitalWrite(BUZZER, HIGH);
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED, LOW);

    delay(500);

    digitalWrite(BUZZER, LOW);

    delay(500);

    lcd.clear();
  }

  // -------------------- Bad Air Quality Alert --------------------
  else if (b / 2 > 70)
  {
    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("Bad Air Quality");

    digitalWrite(BUZZER, HIGH);
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED, LOW);

    delay(500);

    digitalWrite(BUZZER, LOW);

    delay(500);

    lcd.clear();
  }

  // -------------------- Normal Condition --------------------
  else
  {
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, HIGH);
  }
}
