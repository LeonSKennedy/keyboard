#include <wiringPi.h>

// LED Pin - wiringPi pin 0 is BCM_GPIO 17.
// we have to use BCM numbering when initializing with wiringPiSetupSys
// when choosing a different pin number please use the BCM numbering, also
// update the Property Pages - Build Events - Remote Post-Build Event command 
// which uses gpio export for setup for wiringPiSetupSys
#define	LED1	17
#define LED2	18
#define BUTTON1	22
#define CONTROL	4

bool pollButtons() 
{
	return digitalRead(BUTTON1);
}
int main(void)
{
	wiringPiSetupSys();

	pinMode(LED1, OUTPUT);
	pinMode(LED2, OUTPUT);
	pinMode(BUTTON1, INPUT);
	pinMode(CONTROL, INPUT);

	while (true)
	{
		int wireToWrite;
		bool buttonPress;
		bool pressed = digitalRead(CONTROL);
		if (pressed)
		{
			buttonPress = pollButtons();
			if (buttonPress)
			{
				wireToWrite = LED2;
			}
			else 
			{
				wireToWrite = LED1;
			}
			digitalWrite(wireToWrite, HIGH);  // On
			delay(500); // ms
			digitalWrite(wireToWrite, LOW);	  // Off
			delay(500);
		}
	}
	return 0;
}