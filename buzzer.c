#include <Arduino.h>
#include "buzzer.h"

bool buzzer_state;

/* Inicializacao do buzzer */
void  buzzer_init (void)
{
  pinMode(BUZZER, OUTPUT);
  digitalWrite(BUZZER, BUZZER_OFF);
  buzzer_state = BUZZER_OFF;
}

/* Liga o buzer */
void  buzzer_enable (void)
{
	digitalWrite(BUZZER, BUZZER_ON);
  buzzer_state = BUZZER_ON;
}

/* Desliga o buzer */
void buzzer_disable (void)
{
	digitalWrite(BUZZER, BUZZER_OFF);
  buzzer_state = BUZZER_OFF;
}

bool get_buzzer_state (void)
{
  return buzzer_state;
}

/* Habilita o buzzer por um intervalo de tempo */
void buzzer_pulse (int interval_in_ms)
{
  if (buzzer_state == BUZZER_ON) return;

  digitalWrite(BUZZER, BUZZER_ON);
  delay(interval_in_ms);
  digitalWrite(BUZZER, BUZZER_OFF);
}

