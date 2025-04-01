#include <LiquidCrystal.h>
#include <DHT.h>

// Define DHT11 sensor
#define DHTPIN 7        // Signal pin from your DHT11
#define DHTTYPE DHT11   // Using DHT11 sensor

DHT dht(DHTPIN, DHTTYPE);

// Initialize LCD with these pins: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);         // Initialize LCD: 16 columns, 2 rows
  dht.begin();              // Start the DHT11 sensor
  Serial.begin(9600);       // Start serial monitor
}

void loop() {
  float temp = dht.readTemperature();    // Read temperature (Celsius)
  float humidity = dht.readHumidity();   // Read humidity (%)

  // Error checking
  if (isnan(temp) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error!");
    delay(2000);
    return;
  }

  // Print to LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print(" C");

  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(humidity);
  lcd.print(" %");

  // Print to Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print(" C  |  Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  delay(2000); // Wait 2 seconds before next reading
}
