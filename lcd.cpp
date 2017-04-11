#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "lcd.h"

/* Objeto utilizado para comunicacao com o display de LCD */
LiquidCrystal_I2C lcd(LCD_I2C_ADDR, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

/* Inicializacao do display de LCD */
void lcd_init (void)
{
  lcd.begin (LCD_NUMBER_OF_COLUMNS, LCD_NUMBER_OF_ROWS);
  lcd.setBacklight(HIGH);
}

/* Impressao das 2 linhas na tela */
void lcd_print (char *line0, char *line1)
{
  lcd.setCursor(0,0);
  lcd.print(line0);
  lcd.setCursor(0,1);
  lcd.print(line1);
}

