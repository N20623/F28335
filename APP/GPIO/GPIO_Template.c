/**
 * 
 * FileName  GPIO_Template.c
 * 
*/
#include "GPIO_Template.h"


void ConfigInputGPIO(void){

   EALLOW;
   SysCtrlRegs.PCLKCR3.bit.GPIOINENCLK=1; // 使能输入时钟
   EDIS;

   EALLOW;
   GpioCtrlRegs.GPAMUX1.bit.GPIO12=0;
   GpioCtrlRegs.GPADIR.bit.GPIO12=0; // 配置为输入模式
   GpioCtrlRegs.GPAPUD.bit.GPIO12=0; // 开启上拉
   GpioCtrlRegs.GPAQSEL1.bit.GPIO12=0; // 配置输入采样周期 与时钟同步

   GpioCtrlRegs.GPBMUX2.bit.GPIO48=0;
   GpioCtrlRegs.GPBDIR.bit.GPIO48=1;
   GpioCtrlRegs.GPBPUD.bit.GPIO48=0;
   GpioDataRegs.GPBCLEAR.bit.GPIO48=1;

   EDIS;

   // 将外部中断1 映射到外部输入12引脚
   EALLOW;
   GpioIntRegs.GPIOXINT1SEL.bit.GPIOSEL=12;
   EDIS;

//   添加中断映射函数地址
   EALLOW;
   PieVectTable.XINT1=&EXTI1_IRQn;
   EDIS;

   PieCtrlRegs.PIEIER1.bit.INTx4=1; //开启PIE组1的INT4
   XIntruptRegs.XINT1CR.bit.POLARITY = 0; // 下降沿触发
   XIntruptRegs.XINT1CR.bit.ENABLE=1; // 开启INT1的中断

   IER |=M_INT1;  // 开启CPU INT1

   EINT; // 开全局中断
   ERTM; //当使用仿真器调试时可开启 DEBUG 中断，即使用 ERTM 语句
}

interrupt void EXTI1_IRQn(){
    DELAY_US(5000);
    while( !GpioDataRegs.GPADAT.bit.GPIO12);
    GpioDataRegs.GPATOGGLE.bit.GPIO12=1;
    PieCtrlRegs.PIEACK.bit.ACK1=1; //应答中断
}




