#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "buzzer.h"
#include "sensors.h"
#include "utils.h"

uint16_t triggered_sensors = 0;
char msg_line0[16];
char msg_line1[16];

/* Inicializa o display no endereco 0x27 */
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);

/* Inicializacao */
void setup ()
{
  int i;
  
  buzzer_init();
  sensors_init();

  lcd.begin (16,2);
  lcd.setBacklight(HIGH);
  myxmemzero((int *)lcd_msg, sizeof(lcd_msg) / sizeof(int));
}

/* Loop principal */
void loop ()
{
  /* Leitura dos sensores */
  triggered_sensors = sensors_read();
  
  /* Controle do buzzer */
  if (triggered_sensors) buzzer_enable();
  else buzzer_disable();
  
  /* Controle da mensagem para o LCD */
  if (triggered_sensors) mystrcpy(lcd_msg, "     BRUTUS     ALARME ATIVADO ");
  else mystrcpy(lcd_msg, "     BRUTUS      ALARM  SYSTEM ");
  
  /* Impressao da mensagem no LCD */
  lcd.setCursor(0,0);
  lcd.print("     BRUTUS     ");
  lcd.setCursor(0,1);
  lcd.print(" alarme ativado ");
}
