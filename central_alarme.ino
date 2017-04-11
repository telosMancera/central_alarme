#include "alarm_enable.h"
#include "buzzer.h"
#include "lcd.h"
#include "sensors.h"
#include "utils.h"

#define ENABLING_ALARM_BUZZER_PULSE_TIME  2000 // 2s

uint16_t triggered_sensors = 0;
bool alarm_enabled = false;
char msg_line0[LCD_NUMBER_OF_COLUMNS];
char msg_line1[LCD_NUMBER_OF_COLUMNS];

/* Calculo de quantos sensores estao ativados */
int triggered_quantity (void)
{
  int i = 0;
  int qty = 0;

  for (i = 0; i < NUMBER_OF_SENSORS; i++)
  {
    if (triggered_sensors & (1 << i)) qty++;
  }

  return qty;
}

/* Inicializacao */
void setup ()
{
  alarm_enable_init();
  sensors_init();
  buzzer_init();

  lcd_init();
  myxmemzero((int *)msg_line0, sizeof(msg_line0) / sizeof(int));
  myxmemzero((int *)msg_line1, sizeof(msg_line1) / sizeof(int));
}

/* Loop principal */
void loop ()
{
  /* Leitura do enable do alarm */
  if (does_alarm_must_be_enabled())
  {
    if (!alarm_enabled)
    {
      mystrcpy(msg_line0, "     ATIVANDO   ");
      mystrcpy(msg_line1, "     ALARME     ");
      lcd_print(msg_line0, msg_line1);
      
      buzzer_pulse(ENABLING_ALARM_BUZZER_PULSE_TIME);
    }
    
    alarm_enabled = true;
  }
  else alarm_enabled = false;

  /* Maquina de estados de dois estados (alarme habilitado e desabilitado) */
  if (alarm_enabled)
  {
    /* Leitura dos sensores */
    triggered_sensors = sensors_read();

    /* 1 ou mais sensores gatilhados */
    if (triggered_sensors)
    {
      buzzer_enable();

      /*mystrcpy(msg_line0, "      ALARM     ");
      mystrcpy(msg_line1, "    TRIGGERED   ");*/
      mystrcpy(msg_line0, "    TRIGGERED   ");
      mystrcpy(msg_line1, "                ");
      itoa(triggered_quantity(), msg_line1 + 8, 10);
    }
    else
    {
      buzzer_disable();

      mystrcpy(msg_line0, "     SYSTEM     ");
      mystrcpy(msg_line1, "    ACTIVATED   ");
    }
  }
  else
  {
    buzzer_disable();

    mystrcpy(msg_line0, "     BRUTUS     ");
    mystrcpy(msg_line1, "  ALARM SYSTEM  ");
  }
  
  /* Impressao da mensagem no LCD */
  lcd_print(msg_line0, msg_line1);
}
