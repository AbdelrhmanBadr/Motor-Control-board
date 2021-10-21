/*
 * Motor_dash_board.c
 *
 * Created: 17-Oct-21 4:20:19 PM
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

int main(void)
{
	/*Define variables*/
	DCMotor_t DcMotor      = {PORTD,PIN6,PIN7};
	Stepper_t StepperMotor = {PORTD,PIN0,PIN1,PIN2,PIN3,STEPPER_FULL_STEP_MODE};
	Servo_t	  ServoMotor   = {PORTD,PIN5};
	Buzzer_t  Buzzer	   = {PORTD,PIN4};
	uint8	  UserID = 0;	
	uint8     EnterdOption = 0;
	uint16    MotorAngle = 0; /*For servo and stepper angles*/
	
	/*Initiate Hardware*/
	CLCD_Setup();
	KeyPad_Setup();
	DCMotor_Setup(&DcMotor);
	Stepper_Setup(&StepperMotor);
	Servo_Setup(&ServoMotor);
	Buzzer_Setup(&Buzzer);

	while (1)
	{
		LoginSystem();
		GetUserID(&UserID,&Buzzer);
		PrintUserName(UserID);
		
		/*For right user name*/
		if(UserID == MASTER_ID || UserID == ASSISTANT1_ID || UserID == ASSISTANT2_ID || UserID == ASSISTANT3_ID)
		{
			if(UserID == MASTER_ID)
			{
				PrintMasterMsg();
			}
			while(EnterdOption == 0)
			{
				GetChoice(&EnterdOption , &Buzzer);
			}
			
			/*DC motor*/
			if (EnterdOption == DC_MOTOR_CHOICE || UserID == ASSISTANT1_ID)
			{
				PrintScreen(DC_MOTOR_TYPE,SCREEN_1);
				EnterdOption = 0;
				while(EnterdOption == 0)
				{
					GetChoice(&EnterdOption , &Buzzer);
				}
				if(EnterdOption == TURN_ON_CHOICE)
				{
					EnterdOption = 0;
					PrintScreen(DC_MOTOR_TYPE,SCREEN_2);
					while(EnterdOption == 0)
					{
						GetChoice(&EnterdOption , &Buzzer);
					}
					if (EnterdOption == FULL_SPEED_CHOICE)
					{
						EnterdOption = 0;
						PrintScreen(DC_MOTOR_TYPE,SCREEN_3);
						while(EnterdOption == 0)
						{
							GetChoice(&EnterdOption , &Buzzer);
						}
						switch(EnterdOption)
						{
							case CW_CHOICE:DCMotor_MoveCW(&DcMotor); break;
							case CCW_CHOICE:DCMotor_MoveCCW(&DcMotor); break;
						}
					}
					else if (EnterdOption == POT_CHOICE)
					{
						/*Pot*/
						EnterdOption = 0;
					}
					else if (EnterdOption == LM35_CHOICE)
					{
						/*Temp sensor*/
						EnterdOption = 0;
					}
					
				}
				else if (EnterdOption == TURN_OFF_CHOICE)
				{
					DCMotor_Stop(&DcMotor);
				}
			}
			/*Servo angle*/
			else if (EnterdOption == SERVO_MOTOR_CHOICE || UserID == ASSISTANT2_ID)
			{
				EnterdOption = 0;
				PrintScreen(SERVO_MOTOR_TYPE,SCREEN_1);
				GetAngle(&MotorAngle,&Buzzer);
				Servo_WriteAngle(&ServoMotor , MotorAngle);
				_delay_ms(20);
				
			}
			else if (EnterdOption == STEPPER_MOTOR_CHOICE || UserID == ASSISTANT3_ID)
			{
				EnterdOption = 0;
				PrintScreen(STEPPER_MOTOR_TYPE,SCREEN_1);
				while(EnterdOption == 0)
				{
					GetChoice(&EnterdOption , &Buzzer);
				}
				if (EnterdOption == CW_CHOICE)
				{
					EnterdOption = 0;
					PrintScreen(STEPPER_MOTOR_TYPE,SCREEN_2);
					while(EnterdOption == 0)
					{
						GetChoice(&EnterdOption , &Buzzer);
					}
					if (EnterdOption == TURN_ON_CHOICE)
					{
						EnterdOption = 0;
						PrintScreen(STEPPER_MOTOR_TYPE,SCREEN_3);
						GetAngle(&MotorAngle,&Buzzer);
						Stepper_Move(&StepperMotor,STEPPER_CW,MotorAngle);
						
					}
					else if (EnterdOption == CW_CHOICE)
					{
						EnterdOption = 0;
						PrintScreen(STEPPER_MOTOR_TYPE,SCREEN_3);
						GetAngle(&MotorAngle,&Buzzer);
						Stepper_Move(&StepperMotor,STEPPER_CCW,MotorAngle);
					}
				}
				else if (EnterdOption == TURN_OFF_CHOICE)
				{
					EnterdOption = 0;
					Stepper_Stop(&StepperMotor);
				}
			}
			/*Reset*/
			UserID = 0;
			EnterdOption = 0;
			MotorAngle = 0;
			MotorAngle = 0;
		}
		else
		{
			CLCD_PrintString("ERROR ID");
			_delay_ms(1000);
			/*Reset*/
			UserID = 0;
			EnterdOption = 0;
			MotorAngle = 0;
			MotorAngle = 0;
		}	
	}		
}
