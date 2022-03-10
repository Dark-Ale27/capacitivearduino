#include <CapacitiveSensor.h>

CapacitiveSensor capSensor = CapacitiveSensor(4,2);

#include <Servo.h>
Servo myServo;
int threshold = 100;
const int ledPin = 12;

void setup() {
Serial.begin(9600);
pinMode(ledPin, OUTPUT);
myServo.attach(9);


}

void loop() {
delay(1000);
long sensorValue = capSensor.capacitiveSensor(30);
Serial.println(sensorValue);

if (sensorValue > threshold) {

digitalWrite(ledPin, HIGH);
myServo.write(110);
}

else {

digitalWrite(ledPin, LOW);
myServo.write(-50);
}

}
