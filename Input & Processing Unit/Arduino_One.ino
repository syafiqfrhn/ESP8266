#include <SPI.h>
#include <Ultrasonic.h>

//Ultrasonic HC-SR04 library for Arduino, developed by JRodrigoTech
Ultrasonic ultrasonic1 (2,3); //(Trig PIN,Echo PIN)
Ultrasonic ultrasonic2 (6,7); //(Trig PIN,Echo PIN)

const int led1 = 8, led2 = 9;
int status1 = 0, status2 = 0; //1 if vacant, 2 if occupied, 0 initially
float distance1 = 0, distance2 = 0;

void setup ()
{
  Serial.begin (115200);
  SPI.begin (); 
  pinMode (led1,OUTPUT);
  pinMode (led2,OUTPUT); 
}

void loop ()
{
  distance1 = ultrasonic1.Ranging (CM);
  distance2 = ultrasonic2.Ranging (CM);
  
  sensor1 ();
  sensor2 ();
}

//For the first sensor and LED
void sensor1 ()
{
	//The sensor distance in cm, freely to adjust.
	if (distance1 > 5)
	{
		digitalWrite (led1,HIGH);
	
		if (status1 == 0 || status1 == 2)
		{  
			Serial.write ("A1V");
			Serial.flush ();
			delay (5000);
		}
		
		status1 = 1;		
	}
	
	else
	{
		digitalWrite (led1,LOW);
	
		if (status1 == 0 || status1 == 1)
		{  
			Serial.write ("A1O");
			Serial.flush ();
			delay (5000);
		}
	
		status1 = 2;
	}
}

//For the second sensor and LED
void sensor2 ()
{
	//The sensor distance in cm, freely to adjust.
    if (distance2 > 5)
	{
		digitalWrite (led2,HIGH);
    
		if (status2 == 0 || status2 == 2)
		{
			Serial.write ("A2V");
			Serial.flush ();
			delay (5000);
		}
    
		status2 = 1;
	}
	
	else
	{
		digitalWrite (led2,LOW);
    
		if (status2 == 0 || status2 == 1)
		{  
			Serial.write ("A2O");
			Serial.flush ();
			delay (5000);
		}
		
		status2 = 2;
	}
}