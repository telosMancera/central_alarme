#include <Arduino.h>
#include "utils.h"

int myxmemzero (int *buff, int len)
{
	int i;

	for (i = 0; i < len; i++) *buff++ = 0;

	return 0;
}

int mystrcpy (char *dst, char *src)
{
	if (sizeof(src) > sizeof(dst)) return -1;

	while (*src != 0) *dst++ = *src++;

	return 0;
}
