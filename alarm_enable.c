#include <Arduino.h>
#include "alarm_enable.h"

void alarm_enable_init (void)
{
  pinMode(ALARM_ENABLE, INPUT);
}

bool does_alarm_must_be_enabled (void)
{
  if (digitalRead(ALARM_ENABLE) == ALARM_ENABLED) return true;

  return false;
}

