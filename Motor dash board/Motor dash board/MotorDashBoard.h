/*
 * MotorDashBoard.h
 *
 * Created: 18-Oct-21 7:32:31 PM
 *  Author: Abdelrhman
 */ 


#ifndef MOTORDASHBOARD_H_
#define MOTORDASHBOARD_H_

#define  DC_MOTOR_TYPE		(1)
#define  STEPPER_MOTOR_TYPE	(2)
#define  SERVO_MOTOR_TYPE	(3)

#define SCREEN_1		(1)
#define SCREEN_2		(2)
#define SCREEN_3		(3)
#define SCREEN_4		(4)
#define SCREEN_5		(5)

#define DC_MOTOR_CHOICE			('1')
#define SERVO_MOTOR_CHOICE		('2')
#define STEPPER_MOTOR_CHOICE	('3')

#define CW_CHOICE				('1')
#define CCW_CHOICE				('2')

#define TURN_ON_CHOICE			('1')
#define TURN_OFF_CHOICE			('2')

#define FULL_SPEED_CHOICE		('1')
#define POT_CHOICE				('2')
#define LM35_CHOICE				('3')

#define WELCOME_MSG_DELAY_MS	(1000)
#define BOUNCING_TIME_MS		(50)
#define INTRO_MSG_DELAY_MS		(500)

void LoginSystem(void);
void PrintUserName(uint8 Indicator);
void PrintMasterMsg(void);
void PrintScreen(uint8 MotorType, uint8 ScreenNumber);
void GetChoice(uint8 *EnteredOption , Buzzer_t *Buzzer);
void GetUserID (uint8 *UserID , Buzzer_t *Buzzer);
void GetAngle(uint16 *Angle , Buzzer_t *Buzzer);

#endif /* MOTORDASHBOARD_H_ */