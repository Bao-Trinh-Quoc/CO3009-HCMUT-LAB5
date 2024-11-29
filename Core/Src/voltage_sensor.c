/*
 * voltage_sensor.c
 *
 *  Created on: Nov 7, 2024
 *      Author: DELL
 */

#include "voltage_sensor.h"

uint32_t sensorValue = 0;

void readSensor()
{
	sensorValue = HAL_ADC_GetValue(&hadc1);
}
