#include <Arduino.h>
#include "sensors.h"

/* Inicializacao dos pinos dos sensores */
void sensors_init (void)
{
	pinMode(SENSOR_CHANNEL_1, INPUT);
	pinMode(SENSOR_CHANNEL_2, INPUT);
	pinMode(SENSOR_CHANNEL_3, INPUT);
	pinMode(SENSOR_CHANNEL_4, INPUT);
	pinMode(SENSOR_CHANNEL_5, INPUT);
	pinMode(SENSOR_CHANNEL_6, INPUT);
	pinMode(SENSOR_CHANNEL_7, INPUT);
	pinMode(SENSOR_CHANNEL_8, INPUT);
}

/* Leitura dos sensores */
uint16_t sensors_read (void)
{
	int i;
	uint16_t triggered_sensors = 0;

	for (i = SENSOR_CHANNEL_1; i <= SENSOR_CHANNEL_8; i++)
	{
		int sensor_bit;

		sensor_bit = (1 << (i - SENSOR_CHANNEL_1));

		if (digitalRead(i) == SENSOR_TRIGGERED) triggered_sensors |= sensor_bit;
		else if (digitalRead(i) == SENSOR_NOT_TRIGGERED) triggered_sensors &= ~sensor_bit;
	}

	return triggered_sensors;
}
