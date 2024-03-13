/*
 * GPIO_Template.h
 *
 *  Created on: 2024年3月12日
 *      Author: Lenovo
 */
#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File

#ifndef GPIO_TEMPLATE_H
#define GPIO_TEMPLATE_H




void ConfigInputGPIO(void);
interrupt void EXTI1_IRQn(void);

#endif 
