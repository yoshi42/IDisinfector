#define sens_disinfect A1 //not used in last red
#define actuator 3
#define button 4

bool flag_dis = false;

void setup()
{
	pinMode(sens_disinfect, INPUT);
	pinMode(button, INPUT_PULLUP);
	pinMode(actuator, OUTPUT);
	digitalWrite(actuator, LOW);

	Serial.begin(9600);
	Serial.println("Started");
}

void loop()
{
	delay(200);
	Serial.println(analogRead(sens_disinfect));
	if((analogRead(sens_disinfect) >= 255) && flag_dis == false)
	{
		delay(300);
		analogWrite(actuator, 255);
		delay(10);
		analogWrite(actuator, 0);
		flag_dis = true;
	}
	else if ((analogRead(sens_disinfect) <= 255 && flag_dis == true))
	{
		flag_dis = false;
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