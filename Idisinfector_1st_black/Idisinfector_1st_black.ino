#define sensor0 A1
#define button A0
#define actuator 3
#define LED 13

bool flag = false;

void setup()
{
	pinMode(sensor0, INPUT_PULLUP);
	pinMode(button, INPUT_PULLUP);
	pinMode(actuator, OUTPUT);
	digitalWrite(actuator, LOW);
	pinMode(LED, OUTPUT);
	digitalWrite(LED, HIGH);
	Serial.begin(9600);
	Serial.println("Started");
}

void loop()
{
	delay(200);

	if((analogRead(sensor0) <= 255) && flag == false)
	{
		delay(300);
		analogWrite(actuator, 255);
		delay(30);
		analogWrite(actuator, 0);
		flag = true;
	}

	else if (((analogRead(sensor0) >= 255) && flag == true))
	{
		flag = false;
		delay(500);
	}

	if(digitalRead(button) == LOW)
	{
		delay(100);
		analogWrite(actuator, 255);
	}
	else if(digitalRead(button) == HIGH)
	{
		delay(100);
		analogWrite(actuator, 0);
	}
}