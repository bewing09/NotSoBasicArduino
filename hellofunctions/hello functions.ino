#include <Servo.h>
int trigpin = 11;
int echopin = 12;
long duration, cm, inches;
Servo myservo;
void setup()
{
	myservo.attach(5);// says what pin the servo is attached to
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
	inches = getdistance();// makes "inches" equal to what is returned from getdistance.
	if (inches < 10)//if the # of inches is less than 10 do this
	{
		myservo.write(90);// turn the servo slowly
	}
	if (inches > 10)//if the # of inches is greater than 10 do this
	{
		myservo.write(180);// turn the servo fast
	}
}

void print()
{
	Serial.print(inches);// gives the interval "inches"
	Serial.print("in");// gives "in"
	Serial.print(cm);// gives the interval cm
	Serial.print("cm");// prints "cm"
	Serial.println();// puts it in the serial monitor
	delay(250);// wait 250 milliseconds
}
