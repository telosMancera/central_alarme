#ifndef BUZZER_H
#define BUZZER_H

#ifdef __cplusplus
extern "C"
{
#endif

/* Pino do buzzer */
#define BUZZER  4

/* Estados do buzzer */
#define BUZZER_ON  HIGH
#define BUZZER_OFF  (!BUZZER_ON)

void  buzzer_init (void);
void  buzzer_enable (void);
void buzzer_disable (void);
bool get_buzzer_state (void);
void buzzer_pulse (int interval_in_ms);

#ifdef __cplusplus
}
#endif

#endif /* BUZZER_H */

