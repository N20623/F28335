// TI File $Revision: /main/1 $
// Checkin $Date: August 18, 2006   13:52:10 $
//###########################################################################
//
// FILE:   DSP2833x_EPwm.h
//
// TITLE:  DSP2833x Enhanced PWM Module Register Bit Definitions.
//   DSP2833x增强型PWM模块寄存器位定义
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

#ifndef DSP2833x_EPWM_H
#define DSP2833x_EPWM_H


#ifdef __cplusplus
extern "C" {
#endif

//
// Time base control register bit definitions 时基控制寄存器位定义
//
struct TBCTL_BITS {           // bits   description
    Uint16 CTRMODE:2;         // 1:0  计数器模式 00向上 01向下 10向上-下计数 11停止计数   Counter Mode  
    Uint16 PHSEN:1;           // 2   将TBPHS相位寄存器 加载到 计数寄存器TBCTR   0禁止 1当同步信号 SYNCI到来时或者 软件强制同步 计数寄存器装载相位寄存器的值   Phase load enable 
    Uint16 PRDLD:1;           // 3  将 映射寄存器 装载  周期寄存器TBPRD  0 当TBCTR为0时 TBPRD装载影子寄存器值 1 立即加载到TBPRD不使用映射   Active period load 激活周期加载
    Uint16 SYNCOSEL:2;        // 5:4   同步信号输出选择 Sync output select  00 当EPWMxSYNC输出; 01 当TBCTR=0x0000输出; 10 当TBCTR=CMPB输出; 11禁用输出
    Uint16 SWFSYNC:1;         // 6   软件强制同步脉冲 写1 强制异常同步脉冲 仅当SYNCOSEL=0时有效  Software force sync pulse 
    Uint16 HSPCLKDIV:3;       // 9:7   高速时间预分频 TBCLK=SYSCLKOUT/(HSPCLKDIV x CLKDIV)   High speed time pre-scale  默认/2 K=001-111对应2K  1 2 4 6 8 10 12 14
    Uint16 CLKDIV:3;          // 12:10   时间基准时钟预分频  TBCLK=SYSCLKOUT/(HSPCLKDIV x CLKDIV) Timebase clock pre-scale  默认/1 K=000-111对应2的K次方  1 2 4 6 8 16 32 64 128
    Uint16 PHSDIR:1;          // 13 同步的相位方向  0同步信号到来向下计数  1同步信号到来向下计数    Phase Direction 
    Uint16 FREE_SOFT:2;       // 15:14  Emulation mode  仿真模式  00当一次时基计数器增或减计数器停止 01当一次时基计数器完成 一个循环停止
};

union TBCTL_REG {
    Uint16              all;
    struct TBCTL_BITS   bit;
};

//
// Time base status register bit definitions 时基状态寄存器位定义
//
struct TBSTS_BITS {          // bits   description
    Uint16 CTRDIR:1;          // 0 时基计数器方向状态位 0 向下计数 1 向上计数      Counter direction status 计数器方向状态
    Uint16 SYNCI:1;           // 1  当为1有同步事件发生同步输入锁存状态位 0 没有同步事件 1同步事件发生 写1可以清除此位     External input sync status 外部输入同步状态
    Uint16 CTRMAX:1;          // 2  当为1时基计数器达到最大值0xFFFF  --  0计数器没有达到最大值 1 计数器达到最大值 写1可以清除此位      Counter max latched status 计数器最大锁存状态
    Uint16 rsvd1:13;          // 15:3   reserved
};

union TBSTS_REG {
    Uint16              all;
    struct TBSTS_BITS   bit;
};

//
// Compare control register bit definitions 比较控制寄存器位定义
//
struct CMPCTL_BITS {           // bits   description
    Uint16 LOADAMODE:2;        // 0:1  CMPA影子装载模式下装载条件选择模式 00 在CTR=ZERO时 01  在CTR=PRD时  10 在CTR=ZERO或 CTR=PRD时 11 禁止  Active compare A 
    Uint16 LOADBMODE:2;        // 3:2 CMPB影子装载模式下装载条件选择模式 00 在CTR=ZERO时 01  在CTR=PRD时  10 在CTR=ZERO或 CTR=PRD时 11 禁止    Active compare B 
    Uint16 SHDWAMODE:1;        // 4   计数比较A寄存器操作模式 0 影子装载模式 工作在双缓冲下 CPU向影子寄存器写入值 1立即装载模式 CPU向CMPA写入值   Compare A block operating mode
    Uint16 rsvd1:1;            // 5      reserved
    Uint16 SHDWBMODE:1;        // 6   计数比较B寄存器操作模式 0 影子装载模式 工作在双缓冲下 CPU向影子寄存器写入值 1立即装载模式 CPU向CMPB写入值    Compare B block operating mode 
    Uint16 rsvd2:1;            // 7      reserved
    Uint16 SHDWAFULL:1;        // 8   CMPA影子寄存器满标志位 0 CMPA影子缓冲寄存器FIFO未满 1 CMPA影子缓冲寄存器FIFO已满 CPU写入会覆盖当前影子寄存器的值 Compare A Shadow registers full Status 
    Uint16 SHDWBFULL:1;        // 9    CMPB影子寄存器满标志位 0 CMPB影子缓冲寄存器FIFO未满 1 CMPB影子缓冲寄存器FIFO已满 CPU写入会覆盖当前影子寄存器的值   Compare B Shadow registers full Status 
    Uint16 rsvd3:6;            // 15:10  reserved
};

union CMPCTL_REG {
    Uint16                all;
    struct CMPCTL_BITS    bit;
};

//
// 
//
/**
 * Action qualifier register bit definitions 动作限定寄存器位定义
 * TBCTR=TBPRD 时基计数器的值等于周期值 
 * TBCTR=0 时基计数器的值等于0
 * TBCTR=CMPA 时基计数器的值等于比较器A的值 AQ模块进行相应的动作
 * TBCTR=CMPA 时基计数器的值等于比较器B的值 
*/
struct AQCTL_BITS {            // bits   description
    Uint16 ZRO:2;              // 1:0  当时基计数器的值等于0时动作 00 不动作 01 清零 使ePWM输出低 10置位  使ePWM输出高 11翻转 使ePWM输出翻转   Action Counter = Zero 
    Uint16 PRD:2;              // 3:2   当时基计数器的值与周期寄存器的值相等时动作 00 不动作 01 清零 使ePWM输出低 10置位  使ePWM输出高 11翻转 使ePWM输出翻转  Action Counter = Period 
    Uint16 CAU:2;              // 5:4  A上升沿 时基计数器的值与CMPA的值相等动作 00 不动作 01 清零 使ePWMA输出低 10置位  使ePWMA输出高 11翻转 使ePWMA输出翻转   Action Counter = Compare A up
    Uint16 CAD:2;              // 7:6  A下降沿 时基计数器的值与CMPA的值相等动作  00 不动作 01 清零 使ePWMA输出低 10置位  使ePWMA输出高 11翻转 使ePWMA输出翻转  Action Counter = Compare A down
    Uint16 CBU:2;              // 9:8   B上升沿  时基计数器的值与CMPB的值相等动作 00 不动作 01 清零 使ePWMB输出低 10置位  使ePWMB输出高 11翻转 使ePWMB输出翻转 Action Counter = Compare B up
    Uint16 CBD:2;              // 11:10 B下降沿 时基计数器的值与CMPB的值相等动作 00 不动作 01 清零 使ePWMB输出低 10置位  使ePWMB输出高 11翻转 使ePWMB输出翻转 Action Counter = Compare B down
    Uint16 rsvd:4;             // 15:12  reserved
};

union AQCTL_REG {
    Uint16                all;
    struct AQCTL_BITS     bit;
};

//
// Action qualifier SW force register bit definitions 动作软件强制寄存器位定义
//
struct AQSFRC_BITS {            // bits description
    Uint16 ACTSFA:2;            // 1:0 当一次性软件强制A输出被调用时的动作 00 不动作 01 清零 使ePWMA输出低 10置位  使ePWMA输出高 11翻转 使ePWMA输出翻转   Action when One-time SW Force A invoked 
    Uint16 OTSFA:1;             // 2  一次性软件强制ePWMxA输出 0 没有效果 1触发一次性软件强制信号  One-time SW Force A output 
    Uint16 ACTSFB:2;            // 4:3  当一次性软件强制B输出被调用时的动作 00 不动作 01 清零 使ePWMB输出低 10置位  使ePWMB输出高 11翻转 使ePWMB输出翻转 Action when One-time SW Force B invoked 
    Uint16 OTSFB:1;             // 5   一次性软件强制ePWMxB输出 0 没有效果 1触发一次性软件强制信号 One-time SW Force B output 
    Uint16 RLDCSF:2;            // 7:6  AQCSF有效寄存器装载影子寄存器的条件 00 当计数器值为0 ；01 当计数器值为PRD周期寄存器 ；10 当计数器0或者为PRD周期寄存器 11立即加载  Reload from Shadow options 
    Uint16 rsvd1:8;             // 15:8 reserved
};

union AQSFRC_REG {
    Uint16                 all;
    struct AQSFRC_BITS     bit;
};

//
// Action qualifier continuous SW force register bit definitions 动作限定连续软件强制寄存器位定义
//
struct AQCSFRC_BITS {           // bits   description
    Uint16 CSFA:2;              // 1:0  连续软件强制A输出 00强制无效 01 强制A输出低 10 强制A输出高 11强制禁止 在立即装载模式下 连续软件强制发生在下一个TBCLK边沿 在影子模式下 发生在下一个TBCLK  Continuous Software Force on output A 持续软件强制输出A
    Uint16 CSFB:2;              // 3:2  连续软件强制B输出 00强制无效 01 强制A输出低 10 强制A输出高 11强制禁止  Continuous Software Force on output B 持续软件强制输出B
    Uint16 rsvd1:12;            // 15:4   reserved
};

union AQCSFRC_REG {
    Uint16                  all;
    struct AQCSFRC_BITS     bit;
};

//
// As of version 1.1
// Changed the MODE bit-field to OUT_MODE 改变了MODE位字段为OUT_MODE
// Added the bit-field IN_MODE 增加了IN_MODE位字段
// This corresponds to changes in silicon as of F2833x devices 
// Rev A silicon.
//

//
// Dead-band generator control register bit definitions      死区生成控制寄存器位定义                              
//
struct DBCTL_BITS {              // bits   description
    Uint16 OUT_MODE:2;      	 // 1:0  死区模块输出控制 00 ePWMxA 和 ePWMxB不经过死区模块 01 下降沿延时禁止上升沿延时   10 上升沿延时 禁止下降沿延时   11 上升和下降都延迟  Dead Band Output Mode Control  死区输出模式控制
    Uint16 POLSEL:2;             // 3:2   极性选择控制 00  ePWMxA,ePWMxB都不翻转 01 ePWMxA翻转,ePWMxB不翻转 10 ePWMxA不翻转,ePWMxB翻转 ePWMxA,ePWMxB翻转  Polarity Select Control  极性选择控制
    Uint16 IN_MODE:2;            // 5:4   死区模块输入控制; 00--> ePWMxA是双边沿延时输入源 ;01--> ePWMxA是下降沿输入源 ePWMxB是上升沿输入源 ; 10--> ePWMxA是上升沿输入源 ePWMxB是下降沿输入源; 11--> ePWMxB是双边沿延时输入源    Dead Band Input Select Mode Control 死区输入选择模式控制
    Uint16 rsvd1:10;             // 15:4   reserved 
};

union DBCTL_REG {
    Uint16                  all;
    struct DBCTL_BITS       bit;
};

//
// Trip zone select register bit definitions 错误联防选择寄存器位定义
//
struct TZSEL_BITS {            // bits   description
    Uint16  CBC1:1;            // 0  CBC1错误联防1选择TZ1周期触发联防 0禁止 1使能    TZ1 CBC select 错误联防选择1
    Uint16  CBC2:1;            // 1   CBC2错误联防2选择TZ2周期触发联防 0禁止 1使能   TZ2 CBC select
    Uint16  CBC3:1;            // 2  CBC3错误联防3选择TZ3周期触发联防 0禁止 1使能    TZ3 CBC select
    Uint16  CBC4:1;            // 3   CBC4错误联防4选择TZ4周期触发联防 0禁止 1使能   TZ4 CBC select
    Uint16  CBC5:1;            // 4   CBC5错误联防5选择TZ5周期触发联防 0禁止 1使能   TZ5 CBC select
    Uint16  CBC6:1;            // 5    CBC6错误联防6选择TZ6周期触发联防 0禁止 1使能  TZ6 CBC select
    Uint16  rsvd1:2;           // 7:6    reserved
    Uint16  OSHT1:1;           // 8   One-shot错误联防1选择TZ1单次触发联防 0禁止 1使能   One-shot TZ1 select         一次性TZ1选择    
    Uint16  OSHT2:1;           // 9   One-shot错误联防2选择TZ2单次触发联防 0禁止 1使能    One-shot TZ2 select             
    Uint16  OSHT3:1;           // 10   One-shot错误联防3选择TZ3单次触发联防 0禁止 1使能   One-shot TZ3 select             
    Uint16  OSHT4:1;           // 11   One-shot错误联防4选择TZ4单次触发联防 0禁止 1使能   One-shot TZ4 select             
    Uint16  OSHT5:1;           // 12   One-shot错误联防5选择TZ5单次触发联防 0禁止 1使能   One-shot TZ5 select             
    Uint16  OSHT6:1;           // 13   One-shot错误联防6选择TZ6单次触发联防 0禁止 1使能   One-shot TZ6 select             
    Uint16  rsvd2:2;           // 15:14  reserved
};

union TZSEL_REG {
    Uint16                  all;
    struct TZSEL_BITS       bit;
};

//
// Trip zone control register bit definitions
//
struct TZCTL_BITS {          // bits   description
    Uint16 TZA:2;            // 1:0 当错误事件发生的时候 此位决定了ePWMxA的输出状态 00高阻态 01   TZ1 to TZ6 Trip Action On EPWMxA TZ1到TZ6在EPWMxA上的错误联防动作
    Uint16 TZB:2;            // 3:2    TZ1 to TZ6 Trip Action On EPWMxB  TZ1到TZ6在EPWMxB上的错误联防动作
    Uint16 rsvd:12;          // 15:4   reserved
};

union TZCTL_REG {
    Uint16                  all;
    struct TZCTL_BITS       bit;
};

//
// Trip zone control register bit definitions 错误联防中断使能寄存器位定义
//
struct TZEINT_BITS {          // bits   description
    Uint16  rsvd1:1;          // 0      reserved
    Uint16  CBC:1;            // 1      Trip Zones Cycle By Cycle Int Enable 错误联防周期性中断使能
    Uint16  OST:1;            // 2      Trip Zones One Shot Int Enable 错误联防一次性中断使能
    Uint16  rsvd2:13;         // 15:3   reserved
};   

union TZEINT_REG {
    Uint16                  all;
    struct TZEINT_BITS      bit;
};

//
// Trip zone flag register bit definitions 错误联防标志寄存器位定义
//
struct TZFLG_BITS {          // bits   description
    Uint16  INT:1;           // 0      Global status 全局状态
    Uint16  CBC:1;           // 1      Trip Zones Cycle By Cycle Int 错误联防周期性中断
    Uint16  OST:1;           // 2      Trip Zones One Shot Int 错误联防一次性中断
    Uint16  rsvd2:13;        // 15:3   reserved
};

union TZFLG_REG {
    Uint16                  all;
    struct TZFLG_BITS       bit;
};

//
// Trip zone flag clear register bit definitions 错误联防标志清除寄存器位定义
//
struct TZCLR_BITS {          // bits   description
    Uint16  INT:1;           // 0      Global status 全局状态
    Uint16  CBC:1;           // 1      Trip Zones Cycle By Cycle Int 错误联防周期性中断
    Uint16  OST:1;           // 2      Trip Zones One Shot Int 错误联防一次性中断
    Uint16  rsvd2:13;        // 15:3   reserved
};

union TZCLR_REG {
    Uint16                  all;
    struct TZCLR_BITS       bit;
};

//
// Trip zone flag force register bit definitions 错误联防标志强制寄存器位定义
//
struct TZFRC_BITS {          // bits   description
    Uint16  rsvd1:1;         // 0      reserved
    Uint16  CBC:1;           // 1      Trip Zones Cycle By Cycle Int
    Uint16  OST:1;           // 2      Trip Zones One Shot Int
    Uint16  rsvd2:13;        // 15:3   reserved
};

union TZFRC_REG {
    Uint16                  all;
    struct TZFRC_BITS       bit;
};

//
// Event trigger select register bit definitions 事件触发选择寄存器位定义
//
struct ETSEL_BITS {          // bits   description
    Uint16  INTSEL:3;        // 2:0    EPWMxINTn Select EPWMxINTn选择
    Uint16  INTEN:1;         // 3      EPWMxINTn Enable EPWMxINTn使能
    Uint16  rsvd1:4;         // 7:4    reserved
    Uint16  SOCASEL:3;       // 10:8   Start of conversion A Select 转换开始A选择
    Uint16  SOCAEN:1;        // 11     Start of conversion A Enable 转换开始A使能
    Uint16  SOCBSEL:3;       // 14:12  Start of conversion B Select 转换开始B选择
    Uint16  SOCBEN:1;        // 15     Start of conversion B Enable 转换开始B使能
};

union ETSEL_REG {
    Uint16                  all;
    struct ETSEL_BITS       bit;
};

//
// Event trigger pre-scale register bit definitions 事件触发预分频寄存器位定义
//
struct ETPS_BITS {          // bits   description
    Uint16  INTPRD:2;       // 1:0    EPWMxINTn Period Select EPWMxINTn周期选择
    Uint16  INTCNT:2;       // 3:2    EPWMxINTn Counter Register EPWMxINTn计数器寄存器
    Uint16  rsvd1:4;        // 7:4    reserved 
    Uint16  SOCAPRD:2;      // 9:8    EPWMxSOCA Period Select EPWMxSOCA周期选择
    Uint16  SOCACNT:2;      // 11:10  EPWMxSOCA Counter Register EPWMxSOCA计数器寄存器
    Uint16  SOCBPRD:2;      // 13:12  EPWMxSOCB Period Select EPWMxSOCB周期选择
    Uint16  SOCBCNT:2;      // 15:14  EPWMxSOCB Counter Register EPWMxSOCB计数器寄存器
};

union ETPS_REG {
    Uint16                  all;
    struct ETPS_BITS        bit;
};

//
// Event trigger Flag register bit definitions 事件触发标志寄存器位定义
//
struct ETFLG_BITS {          // bits   description
    Uint16  INT:1;           // 0	EPWMxINTn Flag EPWMxINTn标志
    Uint16  rsvd1:1;         // 1	reserved
    Uint16  SOCA:1;          // 2	EPWMxSOCA Flag EPWMxSOCA标志
    Uint16  SOCB:1;          // 3	EPWMxSOCB Flag EPWMxSOCB标志
    Uint16  rsvd2:12;        // 15:4	reserved
};

union ETFLG_REG {
    Uint16                   all;
    struct ETFLG_BITS        bit;
};

//
// Event trigger Clear register bit definitions 事件触发清除寄存器位定义
//
struct ETCLR_BITS {          // bits   description
    Uint16  INT:1;           // 0	EPWMxINTn Clear EPWMxINTn清除
    Uint16  rsvd1:1;         // 1	reserved
    Uint16  SOCA:1;          // 2	EPWMxSOCA Clear EPWMxSOCA清除
    Uint16  SOCB:1;          // 3	EPWMxSOCB Clear EPWMxSOCB清除
    Uint16  rsvd2:12;        // 15:4	reserved
};

union ETCLR_REG {
    Uint16                   all;
    struct ETCLR_BITS        bit;
};

//
// Event trigger Force register bit definitions 事件触发强制寄存器位定义
//
struct ETFRC_BITS {          // bits   description
    Uint16  INT:1;           // 0	EPWMxINTn Force EPWMxINTn强制
    Uint16  rsvd1:1;         // 1	reserved
    Uint16  SOCA:1;          // 2	EPWMxSOCA Force EPWMxSOCA强制
    Uint16  SOCB:1;          // 3	EPWMxSOCB Force EPWMxSOCB强制
    Uint16  rsvd2:12;        // 15:4	reserved
};

union ETFRC_REG {
    Uint16                  all;
    struct ETFRC_BITS        bit;
};

//
// PWM chopper control register bit definitions PWM斩波控制寄存器位定义
//
struct PCCTL_BITS {          // bits   description
    Uint16  CHPEN:1;         // 0    PWM斩波使能 0禁止 1 使能  PWM chopping enable PWM斩波使能
    Uint16  OSHTWTH:4;       // 4:1  脉冲宽度 0000-1111 (1-16)xSYSCLKOUT*8  One-shot pulse width  脉冲的宽度 斩波的第一个脉冲宽度 保证可靠开通
    Uint16  CHPFREQ:3;       // 7:5   斩波时钟频率   000-111  150MHz/8/1-8  SYSCLKOUT/8/(1-8分频) Chopping clock frequency
    Uint16  CHPDUTY:3;       // 10:8  占空比 000 -110  占空比=1/8-7/8 111保留 Chopping clock Duty cycle
    Uint16  rsvd1:5;         // 15:11  reserved
};

union PCCTL_REG {
    Uint16                  all;
    struct PCCTL_BITS       bit;
};

struct HRCNFG_BITS {       	// bits   description
    Uint16  EDGMODE:2;     	// 1:0    Edge Mode select Bits 边沿模式选择位
    Uint16  CTLMODE:1;     	// 2      Control mode Select Bit 控制模式选择位
    Uint16  HRLOAD:1;      	// 3      Shadow mode Select Bit 影子模式选择位
    Uint16  rsvd1:12;      	// 15:4   reserved
};

union HRCNFG_REG {
    Uint16                  	all;
    struct HRCNFG_BITS       bit;
};

struct TBPHS_HRPWM_REG {   	 //bits  description 
    Uint16  TBPHSHR;     	 //15:0 时基相位H高分辨率HRPWM寄存器  Extension register for HRPWM Phase(8 bits) HRPWM相位扩展寄存器
    Uint16  TBPHS;           //31:16 0000-FFFF 时基的相位 如果TBCTL.PHSEN=1 开启同步事件 Phase offset register
};

union TBPHS_HRPWM_GROUP {
    Uint32                  all;
    struct TBPHS_HRPWM_REG  half;
};

struct CMPA_HRPWM_REG { // bits   description
    Uint16  CMPAHR;     // 15:0  时基比较A HRPWMP寄存器 Extension register for HRPWM compare (8 bits) HRPWM比较扩展寄存器
    Uint16  CMPA;       // 31:16  计数比较A寄存器 Compare A reg 与TBCTR比较
};

union CMPA_HRPWM_GROUP {
    Uint32                 all;
    struct CMPA_HRPWM_REG  half;
};

struct EPWM_REGS {
    union  TBCTL_REG           TBCTL;   //  时间基准控制寄存器
    union  TBSTS_REG           TBSTS;   //  时间基准状态寄存器
    union  TBPHS_HRPWM_GROUP   TBPHS;   //  时基相位寄存器集 Union of TBPHS:TBPHSHR HRPWMP扩展相位寄存器
    Uint16                     TBCTR;   // 时基计数寄存器 ++--TBPRD Counter register
    Uint16                     TBPRD;   // 设定时钟周期 0000-FFFFH 默认值是被映射的 映射启动TBCTL[PRDLD]=0 映射关闭TBCTL[PRDLD]=1 Period register set
    Uint16                     rsvd1;   // 
    union  CMPCTL_REG          CMPCTL;  // 计数比较控制寄存器 Compare control
    union  CMPA_HRPWM_GROUP    CMPA;    // 计数比较A寄存器集 与TBCTR比较   Union of CMPA:CMPAHR  HRPWMP计数比较A扩展寄存器
    Uint16                     CMPB;    // 计数比较B寄存器集 Compare B reg 计数比较B寄存器
    union  AQCTL_REG           AQCTLA;  // 输出A的操作限定器控制寄存器A Action qual output A
    union  AQCTL_REG           AQCTLB;  // 输出B的操作限定器控制寄存器A Action qual output B
    union  AQSFRC_REG          AQSFRC;  // 操作限定器软件强制寄存器 Action qual SW force
    union  AQCSFRC_REG         AQCSFRC; // 操作限定器连续SW强制寄存器集  Action qualifier continuous SW force
    union  DBCTL_REG           DBCTL;   // 死区生成控制 Dead-band control
    Uint16                     DBRED;   // 死区生成器上升沿延时计数器 10位 0-1023 Dead-band rising edge delay 死区上升沿延迟
    Uint16                     DBFED;   // 死区生成器下降沿延时计数器 10位 0-1023 Dead-band falling edge delay 死区下降沿延迟
    union  TZSEL_REG           TZSEL;   // 触发器(错误联防)选择寄存器 Trip zone select
    Uint16                     rsvd2;   
    union  TZCTL_REG           TZCTL;   // 触发器(错误联防)控制寄存器 Trip zone control
    union  TZEINT_REG          TZEINT;  // 触发器(错误联防)启用中断 Trip zone interrupt enable
    union  TZFLG_REG           TZFLG;   // 触发器错误联防中断标志 Trip zone interrupt flags
    union  TZCLR_REG           TZCLR;   // 触发器 错误联防清除Trip zone clear
    union  TZFRC_REG    	   TZFRC;   // 触发器 错误联防强制中断Trip zone force interrupt
    union  ETSEL_REG           ETSEL;   // 事件触发选择 Event trigger selection
    union  ETPS_REG            ETPS;    // 事件触发预分频 Event trigger pre-scaler
    union  ETFLG_REG           ETFLG;   // 事件触发标志 Event trigger flags
    union  ETCLR_REG           ETCLR;   //  事件触发清除 Event trigger clear
    union  ETFRC_REG           ETFRC;   // 事件触发软件强制 Event trigger force
    union  PCCTL_REG           PCCTL;   // PWM斩波控制 PWM chopper control
    Uint16                     rsvd3;   // 
    union  HRCNFG_REG          HRCNFG;  // HRPWM配置寄存器 HRPWM Config Reg
};


//
// External References & Function Declarations
//
extern volatile struct EPWM_REGS EPwm1Regs;
extern volatile struct EPWM_REGS EPwm2Regs;
extern volatile struct EPWM_REGS EPwm3Regs;
extern volatile struct EPWM_REGS EPwm4Regs;
extern volatile struct EPWM_REGS EPwm5Regs;
extern volatile struct EPWM_REGS EPwm6Regs;

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of DSP2833x_EPWM_H definition

//
// End of file
//

