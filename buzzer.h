#ifndef BUZZER_H_
#define BUZZER_H_

/* Pino do buzzer */
#define BUZZER			4

/* EstadoS do buzzer */
#define BUZZER_ON		HIGH
#define BUZZER_OFF		(!BUZZER_ON)

#ifdef __cplusplus
extern "C"
{
#endif

	void buzzer_init (void);
	void buzzer_enable (void);
	void buzzer_disable (void);

#ifdef __cplusplus
}
#endif

#endif
