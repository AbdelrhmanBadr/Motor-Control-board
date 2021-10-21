/*
 * Potentiometer.c
 *
 *  Created on: Oct 15, 2021
 *      Author: Abdelrhman
 */


#include "Std_DataType.h"
#include "Math.h"
#include "Atmega32A.h"
#include "Error.h"
#include "DIO.h"
#include "ADC.h"
#include "Potentiometer.h"

void Potentiometer_Setup(Potentiometer_t *Pot)
{
	/*Initiate ADC*/
	ADC_Initiate();
	/*Set pin as input pin*/
	DIO_SetPinDirection(Pot->Port,Pot->Pin,DIO_OUTPUT_PIN);
}
Error_t Potentiometer_GetValueSynch(Potentiometer_t *Pot , uint16 *Value)
{
	Error_t ReturnedError = NoError;
	//ReturnedError = ADC_StartConversionSynch(Pot->Pin , Value);
	return ReturnedError;
}
