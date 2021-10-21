/*
 * main.c
 *
 * Created: 16-Oct-21 7:22:33 AM
 *  Author: Abdelrhman
 */ 



#include "Std_DataType.h"
#include "Math.h"
#include "Atmega32A.h"
#include "util/delay.h"
#include "Error.h"

#include "DIO.h"
#include "GlobalInterrupt.h"
#include "ExternalInterrupt.h"
#include "ADC.h"
#include "Timers.h"

#include "LED.h"
#include "Buzzer.h"
#include "PushButton.h"
#include "SevenSegment.h"
#include "KeyPad.h"
#include "CLCD.h"
#include "Servo.h"
#include "Potentiometer.h"
#include "Stepper.h"
#include "DCMotor.h"
int main (void)
{
	DCMotor_t Motor = {PORTD,PIN7,PIN1};
	DCMotor_Setup(&Motor);
	Timer2_Initiate();
	uint8 i = 0;
	while(1)
	{
		for (i = 0 ; i < 255 ; i+=5)
		{
			DCMotor_ControlSpeed(&Motor,i,DC_MOTOR_CW);
			_delay_ms(500);
		}
			
	}
}


