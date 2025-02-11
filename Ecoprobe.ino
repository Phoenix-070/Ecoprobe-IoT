#include <SoftwareSerial.h>
#include <BlynkSimpleSIM800.h>

// Define sensor pins
#define FLAME_SENSOR_PIN 4
#define MQ135_SENSOR_PIN A0
#define MQ7_SENSOR_PIN A2
#define WATER_SENSOR_PIN 3
#define RAINDROP_SENSOR_PIN 7
#define SOIL_SENSOR_PIN 5

// Define thresholds for MQ135 and MQ7 sensors
#define MQ135_THRESHOLD 500 // Adjust this value according to your needs
#define MQ7_THRESHOLD 300 // Adjust this value according to your needs

// Define software serial pins for SIM800L module
#define SIM800_RX_PIN 2
#define SIM800_TX_PIN 3

char auth[] = "sLq7NO6xbslKtEA5HyB1mjhnxGiAMIjQ "; // Blynk authentication token

SoftwareSerial sim800(SIM800_RX_PIN, SIM800_TX_PIN); // RX, TX

void setup() {
Serial.begin(9600);
sim800.begin(9600); // SIM800L baud rate
delay(10000); // Wait for SIM800L to initialize

Blynk.begin(auth, sim800, " airtelgprs.com ", "", ""); // Your mobile network APN

// Set sensor pins as inputs
pinMode(FLAME_SENSOR_PIN, INPUT);
pinMode(MQ135_SENSOR_PIN, INPUT);
pinMode(MQ7_SENSOR_PIN, INPUT);
pinMode(WATER_SENSOR_PIN, INPUT);
pinMode(RAINDROP_SENSOR_PIN, INPUT);
pinMode(SOIL_SENSOR_PIN, INPUT);
}

void loop() {
Blynk.run();

// Read sensor values
int flameValue = digitalRead(FLAME_SENSOR_PIN);
int mq135Value = analogRead(MQ135_SENSOR_PIN);
int mq7Value = analogRead(MQ7_SENSOR_PIN);
int waterValue = digitalRead(WATER_SENSOR_PIN);
int raindropValue = digitalRead(RAINDROP_SENSOR_PIN);
int soilValue = digitalRead(SOIL_SENSOR_PIN);

// Send sensor data to Blynk cloud
Blynk.virtualWrite(V4, flameValue);
Blynk.virtualWrite(A0, mq135Value);
Blynk.virtualWrite(A1, mq7Value);
Blynk.virtualWrite(V2, waterValue);
Blynk.virtualWrite(V5, raindropValue);
Blynk.virtualWrite(V0, soilValue);

Blynk.virtualWrite(A3, temperatureValue);

delay(1000); // Adjust delay as needed
}


