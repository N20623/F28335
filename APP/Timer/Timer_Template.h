/*
 * Timer_Template.h
 *
 *  Created on: 2024年3月12日
 *      Author: Lenovo
 */
#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File
#ifndef TIMER_TEMPLATE_H
#define TIMER_TEMPLATE_H

void ConfigTimer(float Freq, float Period);

// interrupt  中断函数声明
void TIM0_IRQn(void);

#endif
