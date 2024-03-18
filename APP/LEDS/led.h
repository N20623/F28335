/*
 * led.h
 *
 *  Created on: 2024年3月15日
 *      Author: Lenovo
 */

#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File

#ifndef LED_C
#define LED_C
/**
 * 输出
 */
void ConfigLeds(void);
void ConfigRelay(void);
void ConfigBeep(void);
void ConfigMotor(void);
/**
 * 输入
 */
void ConfigKeys(void);

#endif
