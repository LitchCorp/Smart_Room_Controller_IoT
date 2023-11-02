/* 
 * Project myProject
 * Author: Your Name
 * Date: 
 * For comprehensive documentation and examples, please visit:
 * https://docs.particle.io/firmware/best-practices/firmware-template/
 */



#include "Particle.h"
#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"
#include "Button.h"
#include "IoTClassroom_CNM.h"
#include "Colors.h"
#include "hue.h"

SYSTEM_MODE(MANUAL);

#define OLED_RESET D4
Adafruit_SSD1306 display(OLED_RESET);

Button bP(D3);
bool bS = false;  // Initialize bS to be false initially

const int MW = 5;
const int MW1 = 3;

const int tP = 18;
const int eP = 17;

const int ipR = D19;
const int ipL = D6;

const int buzzerPin = D7; // Connect a buzzer to this pin
bool buzzerActive = false;
bool pirSensorActivated = false;
unsigned long lastPirActivationTime = 0;

const int BULB = 3;
int color;
bool hueBulbsActive = false;

void setup() {
    Serial.begin(9600);
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    display.display();
    delay(2000);
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setRotation(0);

    pinMode(tP, OUTPUT);
    pinMode(eP, INPUT);
    pinMode(ipR, INPUT);
    pinMode(ipL, INPUT);
    pinMode(buzzerPin, OUTPUT);
    digitalWrite(buzzerPin, LOW); // Initialize the buzzer as OFF

    // Initialize Wi-Fi and connect if necessary
    WiFi.on();
    WiFi.setCredentials("IoTNetwork");
    WiFi.connect();
    while (WiFi.connecting()) {
        Serial.print(".");
    }
    delay(1000);
    Serial.println("\n\n");

    display.clearDisplay();
    display.setCursor(0, 0);
    display.printf("Welcome to class!");
    display.display();
}

void loop() {
    if (bP.isPressed()) {
        if (!bS) {
            bS = true;  // Button is pressed and held
            display.clearDisplay();
            display.setCursor(0, 0);
            display.printf("Welcome to class!");
            display.display();
            
        }
    } else {
        if (bS) {
            bS = false;  // Button is released
            display.clearDisplay();
            display.setCursor(0, 0);
            display.printf("Goodbye!");
            display.display();
           
        }
        
    }

    // Control Wemo devices 
    wemoWrite(MW, bS ? HIGH : LOW);
    wemoWrite(MW1, bS ? HIGH : LOW);

    // Control Hue lightbulbs here
    hueBulbsActive = bS;
    if (hueBulbsActive) {
        setHue(BULB, true, HueRainbow[color % 7], random(32, 255), 255);
        color++;
        delay(5000);
        // Control additional Hue bulbs (bulb 1, bulb 2, bulb 4, bulb 5, bulb 6)
        for (int i = 1; i <= 6; i++) {
            if (i != BULB) {
                setHue(i, true, HueRainbow[color % 7], random(32, 255), 255);
            }
        }
    }

    // Ultrasonic Sensor
    digitalWrite(tP, LOW);
    delayMicroseconds(2);
    digitalWrite(tP, HIGH);
    delayMicroseconds(10);
    digitalWrite(tP, LOW);
    int distance = pulseIn(eP, HIGH) / 58; // Calculate distance in centimeters

    // PIR Sensors
    int ipRV = digitalRead(ipR);
    int ipLV = digitalRead(ipL);

    if ((distance >= 0 && distance <= 2) && (ipRV || ipLV) && ipRV) {
        if (!buzzerActive && (pirSensorActivated || (millis() - lastPirActivationTime <= 1000))) {
            // Activate the buzzer when conditions are met
            digitalWrite(buzzerPin, HIGH);
            buzzerActive = true;
        }
    }

    // Track PIR sensor activation
    if (ipRV || ipLV) {
        pirSensorActivated = true;
        lastPirActivationTime = millis();
    } else {
        pirSensorActivated = false;
    }
}
