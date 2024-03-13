/*
 * Interrupt_Template.c
 *
 *  Created on: 2024年3月12日
 *      Author: Lenovo
 */
#include "Interrupt_Template.h"


void ConfigInterrupt(void){


    InitPieCtrl();
    IER = 0x0000;
    IFR = 0x0000;
    InitPieVectTable();
}
