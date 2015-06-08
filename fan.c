#include<stdio.h>
#include<wiringPi.h>
#include<stdlib.h>

#define SW 6	//BCM_GPIO 25
#define OUT1 4	//BCM_GPIO 23
#define OUT2 5	//BCM_GPIO 24
#define LED1 2	//GPIO 27
#define LED2 3	//GPIO 22

int main(void)
{
	if(wiringPiSetup() == -1)
	return 1;

	int trig = 23;
	int echo = 24;
	int start_time, end_time;
	float distance;
	int rMot = 0;	//DC Motor

	pinMode(SW,INPUT);
	pinMode(OUT1,OUTPUT);
	pinMode(OUT2,OUTPUT);
	
	while(1)
	{
		digitalWrite(trig,LOW);
		delay(10);
		digitalWrite(trig,HIGH);
		delayMicroseconds(10);
		digitalWrite(trig,LOW);

		while(digitalRead(echo) == 0);
		start_time = micros();

		while(digitalRead(echo) == 1);
		end_time = micros();

		if(digitalRead(SW) == 1)
		{
			if(rMot == 1)
				rMot = 0;
			else
				rMot = 1;
		}

		if(rMot ==1)
		{
			digitalWrite(OUT1,1);
			digitalWrite(OUT2,0);

			distance = (end_time - start_time) / 29. /2. ;
			printf("distance %.2f cm\n", distance);

			if(distance < 20)
			{
				pinMode(OUT1,OUTPUT);
				pinMode(OUT2,OUTPUT);
				digitalWrite(OUT2,0);
				digitalWrite(OUT1,0);

				PinMode(LED1,OUTPUT);
				pinMode(LED2,OUTPUT);
				digitalWrite(LED2,0);
				digitalWrite(LED1,1);
				delay(200);
				digitalWrite(LED1,0);
				delay(200);
				system("aplay /home/pi/smartfan/match5.wav");
			}
			else
			{
				pinMode(LED1,OUTPUT);
				pinMode(LED2,OUTPUT);
				digitalWrite(LED2,1);
				digitalWrite(LED1,0);
			}
		}
		else
		{
			digitalWrite(OUT1,0);
			digitalWrite(OUT2,0);
			pinMode(LED2,OUTPUT);
			digitalWrite(LED2,0);
		}
	}
	return 0;
}
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
}
