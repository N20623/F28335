/*
 * Timer_Template.c
 *
 *  Created on: 2024年3月12日
 *      Author: Lenovo
 */
#include "Timer_Template.h"
#include "DSP2833x_CpuTimers.h" // 包含时钟的初始化

//  ConfigTimer(150000000,1); // 每秒产生一次中断 150MHz是不分频产生的
void ConfigTimer(float Freq, float Period){

    EALLOW;
     SysCtrlRegs.PCLKCR3.bit.CPUTIMER0ENCLK; // 开启Timer0的外设时钟
    EDIS;


    InitCpuTimers();  // 该函数能直接初始化三个定时器
    /*
    CpuTimer0.RegsAddr=&CpuTimer0Regs; // 指向定时器0的寄存器地址
    CpuTimer0Regs.PRD.all=0xFFFFFFFF; // 设定定时器0的周期值
    // 设定预定标计数器值为0
    CpuTimer0Regs.TPR.all =0;
    CpuTimer0Regs.TPRH.all=0;
    CpuTimer0Regs.TCR.bit.TSS=1; // 确定定时器0为停止
    CpuTimer0Regs.TCR.bit.TRB =1; // 重新装载
    CpuTimer0.InterruptCount =0; // 复位中断计数器值
     */

    ConfigCpuTimer( &CpuTimer0,Freq,Period); // Freq * Period /150 000 000 s


    /***
     *
     * 开启定时0的中断
     */
    EALLOW;
     PieVectTable.TINT0=&TIM0_IRQn;
    EDIS;



    IER |=M_INT1;  // 开启第一组中断
    PieCtrlRegs.PIEIER1.bit.INTx7=1; // 开启第一组的第7个

    // 使能中断
    EINT;
    ERTM;
    CpuTimer0Regs.TCR.bit.TSS=0; // 开始定时

}

int a=0;
// interrupt  中断函数声明不能忘记加
interrupt void TIM0_IRQn(){
    EALLOW;
    a++;
    // do something
    PieCtrlRegs.PIEACK.bit.ACK1=1;
    EDIS;
}

