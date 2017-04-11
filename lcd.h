#ifndef LCD_H
#define LCD_H

#ifdef __cplusplus
extern "C"
{
#endif

#define LCD_NUMBER_OF_ROWS  2
#define LCD_NUMBER_OF_COLUMNS  16
#define LCD_NUMBER_OF_CHARACTERS  (LCD_NUMBER_OF_ROWS * LCD_NUMBER_OF_COLUMNS)

#define LCD_I2C_ADDR  0x27

void lcd_init (void);
void lcd_print (char *line0, char *line1);

#ifdef __cplusplus
}
#endif

#endif /* LCD_H */
