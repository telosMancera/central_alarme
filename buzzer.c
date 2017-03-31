#include  <Arduino.h>
#include  "buzzer.h"

/* Inicializacao do buzzer */
void  buzzer_init (void)
{
	pinMode(BUZZER, OUTPUT);
	digitalWrite(BUZZER, BUZZER_OFF);
}

/* Liga o buzer */
void  buzzer_enable (void)
{
	digitalWrite(BUZZER, BUZZER_ON);
}

/* Desliga o buzer */
void buzzer_disable (void)
{
	digitalWrite(BUZZER, BUZZER_OFF);
}
