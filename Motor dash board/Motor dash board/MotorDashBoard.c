/*
 * MotorDashBoard.c
 *
 * Created: 18-Oct-21 7:32:16 PM
 *  Author: Abdelrhman Badr
 */ 
/*Include Service files*/
#include "Std_DataType.h"
#include "Math.h"
#include "Error.h"
#include "Atmega32A.h"
#include <util/delay.h>

/*Include MCAL files*/
#include "DIO.h"
#include "ADC.h"
#include "Timers.h"

/*include HAL files*/
#include "CLCD.h"
#include "KeyPad.h"
#include "Servo.h"
#include "Stepper.h"
#include "DCMotor.h"
#include "Buzzer.h"
#include "Potentiometer.h"
#include "MotorDashBoard_Config.h"
#include "MotorDashBoard.h"

void LoginSystem(void)
{
	CLCD_ClearCLCD();
	_delay_ms(10);
	CLCD_SetCursor(0,0);
	CLCD_PrintString("Welcome to Motor");
	CLCD_SetCursor(1,1);
	CLCD_PrintString("board control");
	_delay_ms(INTRO_MSG_DELAY_MS);
	CLCD_ClearCLCD();
	_delay_ms(10);
	CLCD_SetCursor(0,0);
	CLCD_PrintString("Enter your ID: ");
	CLCD_SetCursor(0,1);
}
void PrintUserName(uint8 Indicator)
{
	CLCD_ClearCLCD();
	_delay_ms(10);
	switch(Indicator)
	{
		case MASTER_ID : CLCD_SetCursor(0,0); CLCD_PrintString("Welcome Mr:"); CLCD_SetCursor(0,1);CLCD_PrintString(MASTER_NAME);break;
		case ASSISTANT1_ID: CLCD_SetCursor(0,0); CLCD_PrintString("Welcome Mr:"); CLCD_SetCursor(0,1);CLCD_PrintString(ASSISTANT1_NAME); break;
		case ASSISTANT2_ID: CLCD_SetCursor(0,0); CLCD_PrintString("Welcome Mr:"); CLCD_SetCursor(0,1);CLCD_PrintString(ASSISTANT2_NAME); break;
		case ASSISTANT3_ID: CLCD_SetCursor(0,0); CLCD_PrintString("Welcome Mr:"); CLCD_SetCursor(0,1);CLCD_PrintString(ASSISTANT3_NAME); break;
	}
	_delay_ms(WELCOME_MSG_DELAY_MS);
}

void PrintMasterMsg(void)
{
	CLCD_SetCursor(0,0);
	CLCD_PrintString("Motor: 1)DC");
	_delay_ms(1);
	CLCD_SetCursor(0,1);
	CLCD_PrintString("2)Servo 3)Steppr");
	_delay_ms(1);
}

void PrintScreen(uint8 MotorType, uint8 ScreenNumber)
{
	if (MotorType == DC_MOTOR_TYPE)
	{
		switch(ScreenNumber)
		{
			case SCREEN_1: 
							CLCD_ClearCLCD();
							_delay_ms(10);
							CLCD_SetCursor(0,0);
							CLCD_PrintString("1) Turn ON");
							CLCD_SetCursor(0,1);
							CLCD_PrintString("2) Turn OFF");
							break;
			case SCREEN_2:
							CLCD_ClearCLCD();
							_delay_ms(10);
							CLCD_SetCursor(0,0);
							CLCD_PrintString("1)Full Speed");
							CLCD_SetCursor(0,1);
							CLCD_PrintString("2)Pot  3)Lm35"); 
							break;
			case SCREEN_3:
							CLCD_ClearCLCD();
							_delay_ms(10);
							CLCD_SetCursor(0,0);
							CLCD_PrintString("Direction");
							CLCD_SetCursor(0,1);
							CLCD_PrintString("1)CW  2)CCW");
							break;								
		}
	}
	else if (MotorType == SERVO_MOTOR_TYPE)
	{
		switch(ScreenNumber)
		{
			case SCREEN_1:
							CLCD_ClearCLCD();
							_delay_ms(10);
							CLCD_SetCursor(0,0);
							CLCD_PrintString("Servo angle:");
							CLCD_SetCursor(0,1);
							break;
		}
		
	}
	else if (MotorType == STEPPER_MOTOR_TYPE)
	{
		switch(ScreenNumber)
		{
			case SCREEN_1:
							CLCD_ClearCLCD();
							_delay_ms(10);
							CLCD_SetCursor(0,0);
							CLCD_PrintString("1) Turn ON");
							CLCD_SetCursor(0,1);
							CLCD_PrintString("2) Turn OFF");
							break;
			case SCREEN_2:
							CLCD_ClearCLCD();
							_delay_ms(10);
							CLCD_SetCursor(0,0);
							CLCD_PrintString("1) CW");
							CLCD_SetCursor(0,1);
							CLCD_PrintString("2) CCW");
							break;
			case SCREEN_3:
							CLCD_ClearCLCD();
							_delay_ms(10);
							CLCD_SetCursor(0,0);
							CLCD_PrintString("Stepper Angle");
							CLCD_SetCursor(0,1);
							break;
		}
								
	}
}	

void GetChoice(uint8 *EnteredOption , Buzzer_t *Buzzer)
{
	uint8 PressedKey = KEYPAD_NOT_PRESSED;
	KeyPad_GetValue(&PressedKey);
	_delay_ms(BOUNCING_TIME_MS);
	if (PressedKey != KEYPAD_NOT_PRESSED && PressedKey != 'O')
	{
		*EnteredOption = PressedKey;
	}
	while (PressedKey != KEYPAD_NOT_PRESSED)
	{
		KeyPad_GetValue(&PressedKey);
		_delay_ms(BOUNCING_TIME_MS);
		Buzzer_TurnOn(Buzzer);
		_delay_ms(10);
	}
	Buzzer_TurnOff(Buzzer);
}
void GetUserID (uint8 *UserID , Buzzer_t *Buzzer)
{
	uint8 PressedKey = KEYPAD_NOT_PRESSED;
	while(1)
	{
		KeyPad_GetValue(&PressedKey);
		_delay_ms(BOUNCING_TIME_MS);
		if (PressedKey != KEYPAD_NOT_PRESSED && PressedKey != 'O')
		{
			*UserID = (PressedKey - '0') + ((*UserID) * 10);
			CLCD_PrintChar('*');
		}
		if (PressedKey == 'O')
		{
			Buzzer_TurnOn(Buzzer);
			_delay_ms(200);
			break;
		}
		while(PressedKey != KEYPAD_NOT_PRESSED)
		{
			KeyPad_GetValue(&PressedKey);
			_delay_ms(BOUNCING_TIME_MS);
			Buzzer_TurnOn(Buzzer);
			_delay_ms(10);
		}
		Buzzer_TurnOff(Buzzer);
	}
	Buzzer_TurnOff(Buzzer);
}

void GetAngle(uint16 *Angle , Buzzer_t *Buzzer)
{
	uint8 PressedKey;
	*Angle = 0;
	while(1)
	{
		KeyPad_GetValue(&PressedKey);
		_delay_ms(BOUNCING_TIME_MS);
		if (PressedKey != KEYPAD_NOT_PRESSED && PressedKey != 'O')
		{
			CLCD_PrintChar(PressedKey);
			*Angle = (PressedKey - '0') + ((*Angle) * 10);
		}
		if(PressedKey == 'O')
		{
			break;
		}
		while (PressedKey != KEYPAD_NOT_PRESSED)
		{
			KeyPad_GetValue(&PressedKey);
			_delay_ms(BOUNCING_TIME_MS);
			Buzzer_TurnOn(Buzzer);
			_delay_ms(10);
		}
		Buzzer_TurnOff(Buzzer);
	}
}