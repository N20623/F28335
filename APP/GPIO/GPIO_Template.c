/**
 * 
 * FileName  GPIO_Template.c
 * 
*/
#include "GPIO_Template.h"


void ConfigInputGPIO(void){

           EALLOW;
           SysCtrlRegs.PCLKCR3.bit.GPIOINENCLK = 1;    // GPIO input clock
           EDIS;

           EALLOW;
           GpioCtrlRegs.GPAMUX1.bit.GPIO12=0; //  选择12口的功能为GPIO
           GpioCtrlRegs.GPADIR.bit.GPIO12=0; // 选择输入
           GpioCtrlRegs.GPAPUD.bit.GPIO12=0; //  开启内部上拉
           GpioCtrlRegs.GPACTRL.bit.QUALPRD1=0xff; //  SCLKOUTx2(FF) =560
           GpioCtrlRegs.GPAQSEL1.bit.GPIO12 = 1;   // 外部中断1个采样周期(QUALPRD)

           GpioCtrlRegs.GPBMUX2.bit.GPIO48=0; //  选择48口的功能为GPIO
           GpioCtrlRegs.GPBDIR.bit.GPIO48=1; // 选择为输出模式
           GpioCtrlRegs.GPBPUD.bit.GPIO48=0; // 开启内部上拉
           GpioDataRegs.GPBCLEAR.bit.GPIO48=1; // 设置为低电平

           GpioCtrlRegs.GPBMUX2.bit.GPIO49=0; // 选择49口的功能为GPIO
           GpioCtrlRegs.GPBDIR.bit.GPIO49=1;  // 选择为输出模式
           GpioCtrlRegs.GPBPUD.bit.GPIO49=0; // 开启内部上拉
           GpioDataRegs.GPBCLEAR.bit.GPIO49=1; // 设置为低电平

           GpioCtrlRegs.GPCMUX1.bit.GPIO68=0;// 选择68口的功能为GPIO
           GpioCtrlRegs.GPCDIR.bit.GPIO68=1;//  选择为输出模式
           GpioCtrlRegs.GPCPUD.bit.GPIO68=0;// 开启内部上拉
           EDIS;

           EALLOW;
           GpioIntRegs.GPIOXINT1SEL.bit.GPIOSEL = 12;   // XINT1是GPIO12
           EDIS;

           EALLOW; // 修改被保护的寄存器，修改前应添加EALLOW语句
           PieVectTable.XINT1 = &EXTI1_IRQn;
           EDIS;   // EDIS的意思是不允许修改被保护的寄存器

           PieCtrlRegs.PIEIER1.bit.INTx4 = 1;          // 使能PIE组1的INT4

           XIntruptRegs.XINT1CR.bit.POLARITY = 0;      // 下降沿触发中断
           XIntruptRegs.XINT1CR.bit.ENABLE= 1;        // 使能XINT1

           IER |= M_INT1;                              // 使能CPU中断1（INT1）
           EINT;                                       // 开全局中断
           ERTM;
}


        interrupt void EXTI1_IRQn(){  //  中断程序
    		DELAY_US(5000);
    		while(!GpioDataRegs.GPADAT.bit.GPIO12); // 读取GPIO12口的状态
    		GpioDataRegs.GPCTOGGLE.bit.GPIO68=1;   // 切换68口的状态
    		PieCtrlRegs.PIEACK.bit.ACK1=1;  //应答中断
        }




