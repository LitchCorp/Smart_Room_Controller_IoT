/* 
 * Project myProject
 * Author: Your Name
 * Date: 
 * For comprehensive documentation and examples, please visit:
 * https://docs.particle.io/firmware/best-practices/firmware-template/
 */

// Include Particle Device OS APIs
#include "Particle.h"
SYSTEM_MODE(SEMI_AUTOMATIC);
int ipRV, ipLV;
const int ipR = D19, ipL = D6;

void setup() {
  pinMode(ipR,INPUT);
  pinMode(ipL,INPUT);
  Serial.begin(9600);
  waitFor(Serial.isConnected,1000);

}

void loop() {
  ipRV = digitalRead(ipR);
  delay(500);
  ipLV = digitalRead(ipL);
  Serial.printf("%d    ----%i\n",ipRV,ipLV);
}