/*
 * ePWM_Template.c
 *
 *  Created on: 2024年3月6日
 *      Author: Lenovo
 */

#include "ePWM_Template.h"
#include "DSP2833x_EPwm_defines.h"

/**
 *  单边非对称波形
 *  ePWM1A和ePWM1B 独立调制 高电平有效
 *
 * 
 */
void ConfigEPWMInit1(void){

    EALLOW;
    SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 1;   // 开启时基时钟
    SysCtrlRegs.PCLKCR1.bit.EPWM1ENCLK = 1;  //ePWM1 使能时钟
    EDIS;

    InitEPwm1Gpio(); // 配置 EPWM1A  EPWM1B

    EALLOW;
    SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 0;   // 关闭时基时钟
    EDIS;
    // TB时基模块 1000=66.6us
    EPwm1Regs.TBPRD = 9999; //
//    EPwm1Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP; // 设置为up计数模式 设定周期为999+1个时钟周期
    EPwm1Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN; // 设置为up计数模式 设定周期为(999+1)*2个时钟周期
    // 配置比较计数器的值 CC比较模块
    // 当使用向上向下计数模式时 要生成对称的波形 向下计数模式=周期-向上计数
    //  比如 周期为1000 向上计数400的对称值为600
    EPwm1Regs.CMPA.half.CMPA = 4000; //
    EPwm1Regs.CMPB = 6000; //
    EPwm1Regs.TBPHS.half.TBPHS = 0; // 设置相位为 0
    EPwm1Regs.TBCTR = 0x0; // 清除时基计数器值

    EPwm1Regs.TBCTL.bit.PHSEN = TB_DISABLE; // 禁止相位装载
    EPwm1Regs.TBCTL.bit.PRDLD = TB_SHADOW; // TBPRD采用影子寄存器模式
    EPwm1Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_DISABLE; // 禁止同步输出信号
    // 配置TB的时钟周期  TBCLK=SYSCLKOUT/(HSPCLKDIV x CLKDIV)
    EPwm1Regs.TBCTL.bit.HSPCLKDIV=TB_DIV1; // 2n
    EPwm1Regs.TBCTL.bit.CLKDIV=TB_DIV1;  // 2的n次方

    // 设置影子寄存器的值 有立即装载和影子装载
        EPwm1Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW; // 设定 CMPA 为影子寄存器模式
        EPwm1Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
        EPwm1Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO; // 装载时刻 在0时刻装载 在等于PRD时刻装载
        EPwm1Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;

        // AQ触发模块
//       EPwm1Regs.AQCTLA.bit.ZRO = AQ_CLEAR ; // CTR=0
       EPwm1Regs.AQCTLA.bit.CAU = AQ_SET; // CTR=CMPA
       EPwm1Regs.AQCTLA.bit.CBD = AQ_CLEAR; // CTR=CMPB
       EPwm1Regs.AQCTLB.bit.CAU = AQ_SET;
       EPwm1Regs.AQCTLB.bit.CBD = AQ_CLEAR;

       // DB死区模块
       //00 DBA_ALL   A两边沿都延迟信号源  默认模式
       //01 DBB_RED_DBA_FED B上升A下降延迟信号源
       //10 DBA_RED_DBB_FED A上升B下降延迟信号源
       //11 DBB_ALL   B两个边沿都延迟信号源
       EPwm1Regs.DBCTL.bit.IN_MODE=DBA_RED_DBB_FED; //10
       // 延迟计数周期 最大1024 2的10次方
       EPwm1Regs.DBRED=1000;  // 1000个时钟周期6.66us
       EPwm1Regs.DBFED=1000; // 1000个时钟周期6.66us
       // 极性取反		// DB_ACTV_HI      0x0  AB不反相		// DB_ACTV_LOC     0x1  A反相		// DB_ACTV_HIC     0x2  B反相		// DB_ACTV_LO      0x3  AB均反相
       EPwm1Regs.DBCTL.bit.POLSEL=DB_ACTV_HIC;
       //DB_FULL_ENABLE AR+BF  11 =3 普中的书印错了
       //DBB_ENABLE  BF        01 =1
       //DBA_ENABLE  AR        10 =2
       //DB_DISABLE            00 =0
       EPwm1Regs.DBCTL.bit.OUT_MODE=DB_FULL_ENABLE;
       // PC chopper 斩波

       EPwm1Regs.PCCTL.bit.CHPEN=1; // 使能斩波
       EPwm1Regs.PCCTL.bit.OSHTWTH=9; // ((0~F)+1)xSYSCLKOUT*8   10个时钟周期 设置为9
       EPwm1Regs.PCCTL.bit.CHPFREQ=0;   // 频率 150MHz/8/(1-8)  0代表1 就是18.75MHz
       EPwm1Regs.PCCTL.bit.CHPDUTY=3;  // 占空比 (k+1)/8

       // TZ 错误联防

       // ET 事件触发


        EALLOW;
        SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 1;         // Start all the timers synced
        EDIS;

}   











