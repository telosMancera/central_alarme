#include <stdint.h>
#include <Arduino.h>
#include "MyTimer.h"

MyTimer::MyTimer (void)
{
  this->base_value = millis();
  this->last_value = 0;
  this->stopped = true;
}

int MyTimer::start (void)
{
	if (this->stopped) this->base_value = millis();

	this->stopped = false;

	return 0;
}

int MyTimer::stop (void)
{
	if (!this->stopped) this->last_value = millis();

	this->stopped = true;

	return 0;
}

int MyTimer::restart (void)
{
	this->base_value = millis();

	return 0;
}

uint32_t MyTimer::getValue (void)
{
	if (this->stopped) return this->last_value;

	return millis() - this->base_value;
}
