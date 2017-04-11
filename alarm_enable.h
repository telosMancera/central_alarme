#ifndef ALARM_ENABLE_H
#define ALARM_ENABLE_H

#ifdef __cplusplus
extern "C"
{
#endif

#define ALARM_ENABLE  13
#define ALARM_ENABLED  true
#define ALARM_DISABLED  (!ALARM_ENABLED)

void alarm_enable_init (void);
bool does_alarm_must_be_enabled (void);

#ifdef __cplusplus
}
#endif

#endif /* ALARM_ENABLE_H */
