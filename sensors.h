#ifndef SENSORS_H_
#define SENSORS_H_

/* Pinos de cada canal */
enum sensors_enum
{
	SENSOR_CHANNEL_1 = 5, // 4N25 da primeira linha e primeira coluna
	SENSOR_CHANNEL_2,
	SENSOR_CHANNEL_3,
	SENSOR_CHANNEL_4,
	SENSOR_CHANNEL_5,
	SENSOR_CHANNEL_6,
	SENSOR_CHANNEL_7,
	SENSOR_CHANNEL_8,
	SENSOR_CHANNEL_9 // 4N25 da ultima linha e ultima coluna
};

/* Estado dos sensores */
#define SENSOR_TRIGGERED		true
#define SENSOR_NOT_TRIGGERED	(!SENSOR_TRIGGERED)

#ifdef __cplusplus
extern "C"
{
#endif

	void sensors_init (void);
	uint16_t sensors_read (void);

#ifdef __cplusplus
}
#endif

#endif
