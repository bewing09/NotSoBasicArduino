#include <Servo.h>
int trigpin = 11;
int echopin = 12;
long duration, cm, inches;
Servo myservo;
void setup()
{
	myservo.attach(5);
	Serial.begin(9600);
	pinMode(trigpin, OUTPUT);
	pinMode(echopin, INPUT);
}

void loop()
{
	servo();// add servo function to void loop
	print();// add print function to void loop
}

int getdistance()
{
	digitalWrite(trigpin, LOW);
	delayMicroseconds(5); // 5 microseconds delay
	digitalWrite(trigpin, HIGH);
	delayMicroseconds(10); // 10 microsecond delay
	digitalWrite(trigpin, LOW);
	pinMode(echopin, INPUT);
	duration = pulseIn(echopin, HIGH);
	cm = (duration/2) / 29.1;
	inches = (duration/2) / 74;
	return inches; // gives the amount of inches back
}

void servo()
{
	inches = getdistance();
	if (inches < 10)//
	{
		myservo.write(90);
	}
	if (inches > 10)
	{
		myservo.write(180);
	}
}

void print()
{
	Serial.print(inches);//put the interval inches in the serial monitor.
	Serial.print("in");//
	Serial.print(cm);
	Serial.print("cm");
	Serial.println();
	delay(250);
}
