#include <NewPing.h>
#define TRIGGER_PIN 4
#define ECHO_PIN 5
#define MAX_DISTANCE 200
NewPing myHCSR04(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
void setup()
{
	Serial.begin(9600);
	pinMode(9, OUTPUT);
	pinMode(3, OUTPUT);
}

void loop()
{
	int cm = myHCSR04.ping_cm(); // make "cm" the variable
	Serial.println(cm);
	if (cm != 0)// if cm is not zero do this
	{
		if (cm > 10)// if cm is greater than 10 turn on the red light
		{
			digitalWrite(9, HIGH);// turn on red light
			digitalWrite(3, LOW);//turn off blue light
		}
		if (cm < 10) //if cm is less than 10 ten turn on blue light
		{
			digitalWrite(3, HIGH);//turn on blue led
			digitalWrite(9, LOW);//turn off red led
		}
	}
	delay(100);// wait so the HCSR04 can keep up with serial monitor
}
