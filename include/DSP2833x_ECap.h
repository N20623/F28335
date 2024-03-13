// TI File $Revision: /main/1 $
// Checkin $Date: August 18, 2006   13:52:07 $
//###########################################################################
//
// FILE:   DSP2833x_ECap.h
//
// TITLE:  DSP2833x Enhanced Capture Module Register Bit Definitions.
//   增强型捕获模块寄存器位定义
//###########################################################################
// $TI Release: 2833x/2823x Header Files V1.32 $
// $Release Date: June 28, 2010 $
// $Copyright:
// Copyright (C) 2009-2023 Texas Instruments Incorporated - http://www.ti.com/
//
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions 
// are met:
// 
//   Redistributions of source code must retain the above copyright 
//   notice, this list of conditions and the following disclaimer.
// 
//   Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the 
//   documentation and/or other materials provided with the   
//   distribution.
// 
//   Neither the name of Texas Instruments Incorporated nor the names of
//   its contributors may be used to endorse or promote products derived
//   from this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// $
//###########################################################################

#ifndef DSP2833x_ECAP_H
#define DSP2833x_ECAP_H


#ifdef __cplusplus
extern "C" {
#endif

//
// Capture control register 1 bit definitions 捕获控制寄存器1位定义
//
struct ECCTL1_BITS {           // bits   description
    Uint16 CAP1POL:1;          // 0 捕获1 极性选择 0-> 上升沿 1->下降沿     Capture Event 1 Polarity select 捕获事件1极性选择
    Uint16 CTRRST1:1;          // 1 捕获1 计数器复位 0 不复位计数器 绝对时间运行 1 复位计数器 差分模式运行      Counter Reset on Capture Event 1 捕获事件1上的计数器复位
    Uint16 CAP2POL:1;          // 2 捕获2 极性选择 0-> 上升沿 1->下降沿     Capture Event 2 Polarity select 捕获事件2极性选择
    Uint16 CTRRST2:1;          // 3 捕获2 计数器复位 0 不复位计数器 绝对时间运行 1 复位计数器 差分模式运行      Counter Reset on Capture Event 2 捕获事件2上的计数器复位
    Uint16 CAP3POL:1;          // 4  捕获3 极性选择 0-> 上升沿 1->下降沿    Capture Event 3 Polarity select 捕获事件3极性选择
    Uint16 CTRRST3:1;          // 5  捕获3 计数器复位 0 不复位计数器 绝对时间运行 1 复位计数器 差分模式运行     Counter Reset on Capture Event 3 捕获事件3上的计数器复位
    Uint16 CAP4POL:1;          // 6 捕获4 极性选择 0-> 上升沿 1->下降沿     Capture Event 4 Polarity select 捕获事件4极性选择
    Uint16 CTRRST4:1;          // 7 捕获4 计数器复位 0 不复位计数器 绝对时间运行 1 复位计数器 差分模式运行      Counter Reset on Capture Event 4 捕获事件4上的计数器复位
    Uint16 CAPLDEN:1;          // 8  使能1-4的装载  1使能 0禁止     Enable Loading CAP1-4 regs on a Cap  触发事件时使能加载CAP1-4寄存器
                               //        Event
    Uint16 PRESCALE:5;         // 13:9 事件滤除预定标 除以 0是1 ( 00000-11111---> 1-62) 2*(00000---11111)  Event Filter prescale select 事件滤波器预分频选择
    Uint16 FREE_SOFT:2;        // 15:14  Emulation mode 仿真模式  00仿真挂起立即停止  01计数器运行到 1x 计数器不受控制
};

union ECCTL1_REG {
    Uint16              all;
    struct ECCTL1_BITS  bit;
};

//
// In V1.1 the STOPVALUE bit field was changed to 
// STOP_WRAP.  This correlated to a silicon change from
// F2833x Rev 0 to Rev A. 
//

//
// Capture control register 2 bit definitions 捕获控制寄存器2位定义
//
struct ECCTL2_BITS {          // bits   description
    Uint16 CONT_ONESHT:1;      // 0  0 连续  1 单次    Continuous or one-shot 连续或单次
    Uint16 STOP_WRAP:2;        // 2:1 00-11--->cap1-cap4之后 单次停止,连续返回    Stop value for one-shot, Wrap for continuous 停止单次模式的值
    Uint16 REARM:1;            // 3   0无效 1 ->单次序列强制 将mod4复位0 启动mod4计数器 使能捕获寄存器装载      One-shot re-arm 强制功能在单次或连续模式有效
    Uint16 TSCTRSTOP:1;        // 4   0 TSCTR停止 1 TSCTR运行   TSCNT counter stop TSCNT计数器停止
    Uint16 SYNCI_EN:1;         // 5    TSCTR同步模式 0 禁止内部同步  1 通过SYNCI信号或者SW强制使CTRPHS装载 Counter sync-in select 计数器同步选择
    Uint16 SYNCO_SEL:2;        // 7:6  同步选择 00 选择内部信号为同步 01 选择CTR=PRD 为外部同步  10+11都是禁止外部同步     Sync-out mode select 同步输出模式选择
    Uint16 SWSYNC:1;           // 8   软件强制TSCTR同步 0无效 1强制EPWM的TSCTR的映射装载   SW forced counter sync 软件强制计数器同步
    Uint16 CAP_APWM:1;         // 9   运行模式  0 CTR=PRD禁止TSCTR复位  10 CTR=PRD TSCTR复位   CAP/APWM operating mode select CAP/APWM操作模式选择
    Uint16 APWMPOL:1;          // 10  极性选择 0输出为高电平有效 1低电平  APWM output polarity select APWM输出极性选择
    Uint16 rsvd1:5;            // 15:11  
};

union ECCTL2_REG {
    Uint16              all;
    struct ECCTL2_BITS  bit;
};

//
// ECAP interrupt enable register bit definitions 捕获中断使能寄存器位定义
//
struct ECEINT_BITS {           // bits   description
    Uint16 rsvd1:1;            // 0      reserved
    Uint16 CEVT1:1;            // 1   cap1中断使能 0禁止  1允许   Capture Event 1 Interrupt Enable 捕获事件1中断使能
    Uint16 CEVT2:1;            // 2   cap2中断使能 0禁止  1允许    Capture Event 2 Interrupt Enable 捕获事件2中断使能
    Uint16 CEVT3:1;            // 3   cap3中断使能 0禁止  1允许    Capture Event 3 Interrupt Enable 捕获事件3中断使能
    Uint16 CEVT4:1;            // 4   cap4中断使能 0禁止  1允许   Capture Event 4 Interrupt Enable  捕获事件4中断使能
    Uint16 CTROVF:1;           // 5    计数器溢出 0禁止  1允许    Counter Overflow Interrupt Enable 计数器溢出中断使能
    Uint16 CTR_EQ_PRD:1;       // 6   计数器=周期值 中断  0禁止  1允许    Period Equal Interrupt Enable 周期相等中断使能
    Uint16 CTR_EQ_CMP:1;       // 7  计数器=比较器 中断  0禁止  1允许     Compare Equal Interrupt Enable 比较相等中断使能
    Uint16 rsvd2:8;            // 15:8   reserved
};

union ECEINT_REG {
   Uint16              all;
   struct ECEINT_BITS  bit;
};

//
// ECAP interrupt flag register bit definitions 捕获中断标志寄存器位定义
//
struct ECFLG_BITS {           // bits   description
    Uint16 INT:1;              // 0  全局中断标志 0未产生 1产生    Global Flag for all interrupts 所有中断的全局标志
    Uint16 CEVT1:1;            // 1   cap1 0未产生 1产生   Capture Event 1 Interrupt Flag 捕获事件1中断标志
    Uint16 CEVT2:1;            // 2    cap2 0未产生 1产生       Capture Event 2 Interrupt Flag 捕获事件2中断标志
    Uint16 CEVT3:1;            // 3    cap3 0未产生 1产生       Capture Event 3 Interrupt Flag 捕获事件3中断标志
    Uint16 CEVT4:1;            // 4     cap4 0未产生 1产生      Capture Event 4 Interrupt Flag   捕获事件4中断标志
    Uint16 CTROVF:1;           // 5  计数器溢出 适用于CAP和APWM 0没有 1 -> TSCTR已经=0    Counter Overflow Interrupt Flag 计数器溢出中断标志
    Uint16 CTR_EQ_PRD:1;       // 6  计数器等于周期值 只适用于APWM   1 -> TSCTR已经=APRD并复位   Period Equal Interrupt Flag 周期相等中断标志
    Uint16 CTR_EQ_CMP:1;       // 7  计数器等于比较寄存器 只适用于APWM    1 -> TSCTR=ACMP    Compare Equal Interrupt Flag 比较相等中断标志
    Uint16 rsvd2:8;            // 15:8   reserved
};

union ECFLG_REG {
    Uint16              all;
    struct ECFLG_BITS   bit;
};

struct ECAP_REGS {
    Uint32              TSCTR;    // 捕获时间基准的32位计数器 Time stamp counter  时间戳计数器
    Uint32              CTRPHS;   // 计数器相位控制 Counter phase 计数器相位
    Uint32              CAP1;     // Capture 1 
    Uint32              CAP2;     // Capture 2    
    Uint32              CAP3;     // Capture 3 
    Uint32              CAP4;     // Capture 4   
    Uint16              rsvd1[8]; // reserved
    union   ECCTL1_REG  ECCTL1;   // eCAP控制1 Capture Control Reg 1
    union   ECCTL2_REG  ECCTL2;   // eCAP控制1 Capture Control Reg 2
    union   ECEINT_REG  ECEINT;   //中断开启 与ECFRC 强制软件中断是同一类型 ECAP interrupt enable ECAP
    union   ECFLG_REG   ECFLG;    //中断标志 与ECCLR 中断清除是同一类型 ECAP interrupt flags ECAP
    union   ECFLG_REG   ECCLR;    //中断清除 ECAP interrupt clear ECAP
    union   ECEINT_REG  ECFRC;    //中断强制 ECAP interrupt force ECAP
    Uint16              rsvd2[6]; // reserved   
};

//
// GPI/O External References & Function Declarations 外部引脚引用和函数声明
//
extern volatile struct ECAP_REGS ECap1Regs; 
extern volatile struct ECAP_REGS ECap2Regs;
extern volatile struct ECAP_REGS ECap3Regs;
extern volatile struct ECAP_REGS ECap4Regs;
extern volatile struct ECAP_REGS ECap5Regs;
extern volatile struct ECAP_REGS ECap6Regs;

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of DSP2833x_ECAP_H definition

//
// End of file
//

