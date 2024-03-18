/*
 * eCAP_Template.c
 *
 *   增强型脉冲捕获  150MHz的时间分辨率6.67ns*2的32次方=28秒 最大
 *  Created on: 2024年3月13日
 *      Author: Lenovo
 */
#include "eCAP_Template.h"

long Period1;
long Period2;
long Period3;

/**
 *   eCap模式 单次捕获
 */
void ConfigEcap(){
    EALLOW;

    SysCtrlRegs.PCLKCR1.bit.ECAP1ENCLK=1; // 开启eCAP1外设时钟
    EDIS;

    // 初始化 GPIO为eCAP1的功能
    InitECap1Gpio(); // GPIO24  开启上拉 设置采样周期和系统时钟同步 选择功能为CAP1

    ECap1Regs.ECEINT.all = 0x0000; // 关闭所有捕获中断
    ECap1Regs.ECCLR.all = 0xFFFF; // 清除所有中断标志位

    ECap1Regs.ECCTL1.bit.CAPLDEN = 0; // 关闭cap 1-4的寄存器装载
    ECap1Regs.ECCTL2.bit.TSCTRSTOP = 0; // 确保计数器停止

    // 配置外设


    ECap1Regs.ECCTL1.bit.CAP1POL = 0; //1下降沿 0上升沿
    ECap1Regs.ECCTL1.bit.CAP2POL = 1; //
    ECap1Regs.ECCTL1.bit.CAP3POL = 0; //
    ECap1Regs.ECCTL1.bit.CAP4POL = 1; //

    ECap1Regs.ECCTL1.bit.CTRRST1 = 1; //0绝对时间  1相对时间运行
    ECap1Regs.ECCTL1.bit.CTRRST2 = 1; //0绝对时间  1相对时间运行
    ECap1Regs.ECCTL1.bit.CTRRST3 = 1; //0绝对时间  1相对时间运行
    ECap1Regs.ECCTL1.bit.CTRRST4 = 1; //0绝对时间  1相对时间运行


    ECap1Regs.ECCTL1.bit.PRESCALE =0; // 不分频 0=1 2K

    ECap1Regs.ECCTL2.bit.CAP_APWM=0; // 当作cap引脚
    ECap1Regs.ECCTL2.bit.CONT_ONESHT = 1; // 配置单次模式
//    ECap1Regs.ECCTL2.bit.STOP_WRAP = 3; // 配置在事件4之后停止

    ECap1Regs.ECCTL2.bit.CONT_ONESHT = 0; // 配置连续模式
    ECap1Regs.ECCTL2.bit.STOP_WRAP = 3; // 配置在事件4之后 mod4归0


    ECap1Regs.ECCTL2.bit.SYNCI_EN = 0; // 关闭同步输入
    ECap1Regs.ECCTL2.bit.SYNCO_SEL = 2; // 关闭

    ECap1Regs.ECCTL2.bit.TSCTRSTOP = 1; // 开启计数

    ECap1Regs.ECCTL2.bit.REARM = 1; // 设置为单次强制 arm one-shot
//    ECap1Regs.ECCTL2.bit.REARM = 0; // 连续模式
    ECap1Regs.ECCTL1.bit.CAPLDEN = 1; // 开启cap1-4寄存器装载

    ECap1Regs.ECEINT.bit.CEVT4 = 1; //  捕获事件4 = 中断


    // 配置中断
    EALLOW;
    PieVectTable.ECAP1_INT = &Ecap1_isr;
    EDIS;
    IER |= M_INT4;
    PieCtrlRegs.PIEIER4.bit.INTx1 = 1;
    EINT;
    ERTM;
}

/**
 * 捕获中断函数
 */
interrupt void Ecap1_isr(){

    Period1=ECap1Regs.CAP2-ECap1Regs.CAP1; // 计算关闭时间 在绝对时间中
    Period2=ECap1Regs.CAP3-ECap1Regs.CAP2; // 计算打开时间
    Period3=ECap1Regs.CAP4-ECap1Regs.CAP3; // 计算关闭时间
    ECap1Regs.ECCLR.bit.CEVT4=1; //清除事件4产生的中断
    ECap1Regs.ECCLR.bit.INT=1; // 清除捕获单元的全局中断
    //响应中断
    PieCtrlRegs.PIEACK.bit.ACK4=1; //响应第四组中断
//    ECap1Regs.ECCTL2.bit.REARM = 1; // 复位计数器
}


/**
 *   APWM模式
 *   配置同步 50Hz 配置三相同步，每个相位差120度 需要加大采样时间才能采样完整
 *   当TSCTR=周期时同步
 *   ECap1Regs.CAP1周期  ECap1Regs.CAP2比较寄存器
 *   ECap1Regs.CAP3 和 ECap1Regs.CAP4作为影子周期和比较器
 *
 *      必须先配置初始化功能 再配置PWM周期时间
 */
void ConfigAPWM(){
//    配置引脚 开启上拉 设置采样周期和系统时钟同步 选择功能为CAP1
    InitECap1Gpio();  // gpio24
    InitECap2Gpio();  // gpio7
    InitECap3Gpio();  // gpio9

    ECap1Regs.ECCTL2.bit.CAP_APWM=1; // 当作PWM引脚
    ECap1Regs.CAP1=3000000; // 设置周期 时钟基准为SYSCLOCK 150MHz 6.66us  3000_000为50Hz
    ECap1Regs.CTRPHS=0x0; // 设置相位的偏移值
    ECap1Regs.ECCTL2.bit.APWMPOL=0 ; // 设置为高电平
    ECap1Regs.ECCTL2.bit.SYNCI_EN=0; // 主模块不需要同步
    ECap1Regs.ECCTL2.bit.SYNCO_SEL=1; // cap1为主模块
    ECap1Regs.ECCTL2.bit.TSCTRSTOP=1; // 运行TSCTR

    ECap2Regs.ECCTL2.bit.CAP_APWM=1; // 当作PWM引脚
    ECap2Regs.CAP1=3000000; // 设置周期
    ECap2Regs.CTRPHS=1000000; // 设置相位的偏移值  -->120°  3000000/3=1000000
    ECap2Regs.ECCTL2.bit.APWMPOL=0 ; // 设置为高电平
    ECap2Regs.ECCTL2.bit.SYNCI_EN=1; // 设置为从模块
    ECap2Regs.ECCTL2.bit.SYNCO_SEL=0; // 内部信号为外部同步
    ECap2Regs.ECCTL2.bit.TSCTRSTOP=1; // 运行TSCTR

    ECap3Regs.ECCTL2.bit.CAP_APWM=1; // 当作PWM引脚
    ECap3Regs.CAP1=3000000; // 设置周期
    ECap3Regs.CTRPHS=2000000; // 设置相位的偏移值
    ECap3Regs.ECCTL2.bit.APWMPOL=0 ; // 设置为高电平
    ECap3Regs.ECCTL2.bit.SYNCI_EN=1; // 设置为从模块
    ECap3Regs.ECCTL2.bit.SYNCO_SEL=2; // 同步信号截止
    ECap3Regs.ECCTL2.bit.TSCTRSTOP=1; // 运行TSCTR

    ECap1Regs.CAP2=1500000; //设置占空比
    ECap2Regs.CAP2=1500000; //设置占空比
    ECap3Regs.CAP2=1500000; //设置占空比



}



