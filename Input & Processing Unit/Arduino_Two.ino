#include <SPI.h>
#include <Ultrasonic.h>

//Ultrasonic HC-SR04 library for Arduino, developed by JRodrigoTech
Ultrasonic ultrasonic3 (2,3); //(Trig PIN,Echo PIN)
Ultrasonic ultrasonic4 (6,7); //(Trig PIN,Echo PIN)

const int led3 = 8, led4 = 9;
int status3 = 0, status4 = 0; //1 if vacant, 2 if occupied, 0 initially
float distance3 = 0, distance4 = 0;

void setup ()
{
  Serial.begin (115200);
  SPI.begin (); 
  pinMode (led3,OUTPUT);
  pinMode (led4,OUTPUT); 
}

void loop ()
{
  distance3 = ultrasonic3.Ranging (CM);
  distance4 = ultrasonic4.Ranging (CM);
  
  sensor3 ();
  sensor4 ();
}

//For the third sensor and LED
void sensor3 ()
{
	//The sensor distance in cm, freely to adjust.
	if (distance3 > 5)
	{
		digitalWrite (led3,HIGH);
	
		if (status3 == 0 || status3 == 2)
		{  
			Serial.write ("A3V");
			Serial.flush ();
			delay (5000);
		}
		
		status3 = 1;		
	}
	
	else
	{
		digitalWrite (led3,LOW);
	
		if (status3 == 0 || status3 == 1)
		{  
			Serial.write ("A3O");
			Serial.flush ();
			delay (5000);
		}
	
		status3 = 2;
	}
}

//For the second sensor and LED
void sensor4 ()
{
	//The sensor distance in cm, freely to adjust.
    if (distance4 > 5)
	{
		digitalWrite (led4,HIGH);
    
		if (status4 == 0 || status4 == 2)
		{
			Serial.write ("A4V");
			Serial.flush ();
			delay (5000);
		}
    
		status4 = 1;
	}
	
	else
	{
		digitalWrite (led4,LOW);
    
		if (status4 == 0 || status4 == 1)
		{  
			Serial.write ("A4O");
			Serial.flush ();
			delay (5000);
		}
		
		status4 = 2;
	}
}