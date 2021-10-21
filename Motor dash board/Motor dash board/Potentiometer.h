/*
 * Potentiometer.h
 *
 *  Created on: Oct 15, 2021
 *      Author: Abdelrhman Badr
 */

#ifndef POTENTIOMETER_H_
#define POTENTIOMETER_H_

typedef struct
{
	uint8 Port;
	uint8 Pin;
}Potentiometer_t;

void Potentiometer_Setup(Potentiometer_t *Pot);
Error_t Potentiometer_GetValueSynch(Potentiometer_t *Pot , uint16 *Value);
#endif /* POTENTIOMETER_H_ */
