#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>


const char* ssid = "SKY8HQFS";     // your network SSID (name of wifi network)
const char* password = "r8AgpHfhXkAB"; // your network password
const int analogPin = A0;

static const uint8_t D0 = 16;
static const uint8_t D1 = 2;
static const uint8_t D2 = 4;
static const uint8_t D3 = 0;
static const uint8_t D4 = 5;
static const uint8_t D5 = 14;
static const uint8_t D6 = 12;
static const uint8_t D7 = 13;
static const uint8_t D8 = 15;
static const uint8_t D9 = 3;
static const uint8_t D10 = 1;

int LED_pin = 2;

void setup()
{
	pinMode(LED_BUILTIN, OUTPUT);
	Serial.begin(115200);
	delay(100);
	Serial.print("Attempting to connect to SSID: ");
	Serial.println(ssid);
	Serial.print("Attempting to connect to password: ");
	Serial.println(password);
	WiFi.begin(ssid, password);

	pinMode(LED_pin, OUTPUT);

	while (WiFi.status() != WL_CONNECTED) {
		digitalWrite(LED_pin, HIGH);
		digitalWrite(LED_BUILTIN, LOW); // low is turn on
		Serial.println(WiFi.status());
		delay(1000);
		digitalWrite(LED_BUILTIN, HIGH); // high is turn off
		
		digitalWrite(LED_pin, LOW);
	}

	digitalWrite(LED_pin, HIGH);

	Serial.println("Connected to ");
	Serial.println(ssid);
	WiFi.hostname("Study Temperature");
	Serial.println(WiFi.localIP);
	pinMode(5, INPUT);

}

// Add the main program code into the continuous loop() function
void loop()
{
	if (WiFi.status() == WL_CONNECTED) {
	digitalWrite(LED_BUILTIN, LOW); // low is turn on
	delay(1000);
	int sensorVal = analogRead(analogPin);
	Serial.print("Sensor: ");
	Serial.print(sensorVal);

	float  voltage = (sensorVal / 1024.0) *3.3;

	Serial.print(", Voltage: ");
	Serial.print(voltage);

	float temperature = (voltage - .5) * 100;


	Serial.print(", degrees C:");
	Serial.print(temperature);
	Serial.println();

	digitalWrite(LED_BUILTIN, HIGH); // high is turn off
	delay(2000);
	}
	
}
