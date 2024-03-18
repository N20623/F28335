/*
 * eCAP_Template.h
 *
 *  Created on: 2024年3月13日
 *      Author: Lenovo
 */
#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File


#ifndef ECAP_TEMPLATE_H
#define ECAP_TEMPLATE_H

void ConfigEcap(void);

void ConfigAPWM(void);
void Ecap1_isr(void);

#endif
