/*
 * GPIO_Template.h
 *
 *  Created on: 2024年3月12日
 *      Author: Lenovo
 */

#ifndef GPIO_TEMPLATE_H
#define GPIO_TEMPLATE_H

#include "DSP2833x_Examples.h"
#include "DSP2833x_Device.h"


void ConfigInputGPIO(void);
interrupt void EXTI1_IRQn(void);

#endif 
