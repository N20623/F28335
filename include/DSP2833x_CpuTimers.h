// TI File $Revision: /main/4 $
// Checkin $Date: March 20, 2007   15:33:42 $
//###########################################################################
//
// FILE:    DSP2833x_CpuTimers.h
//
// TITLE:   DSP2833x CPU 32-bit Timers Register Definitions.
//   32位定时器寄存器定义
// NOTES:   CpuTimer1 and CpuTimer2 are reserved for use with DSP BIOS and
//          other realtime operating systems.
//    不要使用CpuTimer1和CpuTimer2，因为它们是为DSP BIOS和其他实时操作系统保留的
//          Do not use these two timers in your application if you ever plan
//          on integrating DSP-BIOS or another realtime OS.
//   如果你打算集成DSP-BIOS或其他实时操作系统，不要在你的应用程序中使用这两个定时器
//          For this reason, comment out the code to manipulate these two 
//          timers if using DSP-BIOS or another realtime OS.
//  因此，如果使用DSP-BIOS或其他实时操作系统，请注释掉操作这两个定时器的代码
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

#ifndef DSP2833x_CPU_TIMERS_H
#define DSP2833x_CPU_TIMERS_H

#ifdef __cplusplus
extern "C" {
#endif

//
// CPU Timer Register Bit Definitions
//

//
// TCR: Control register bit definitions  时钟控制寄存器位定义
//
struct  TCR_BITS {           // bits  description
    Uint16    rsvd1:4;       // 3:0   reserved 保留
    Uint16    TSS:1;         // 4  定时器启动/停止 0启动 1停止   Timer Start/Stop 
    Uint16    TRB:1;         // 5   定时器重新载控制位 0禁止重载 1使能重载 Timer reload 定时器重载
    Uint16    rsvd2:4;       // 9:6   reserved 保留
    Uint16    SOFT:1;        // 10      仿真模式  Emulation modes  10和11位控制 00下次递减操作完成后定时器停止 01 减到0后停止 10 自由运行 11 自由运行 
    Uint16    FREE:1;        // 11      定时器仿真模式 Free run or restart 
    Uint16    rsvd3:2;       // 12:13 reserved 保留
    Uint16    TIE:1;         // 14    中断使能  Output enable 如果定时器减到0 TIE为使能 向CPU申请中断
    Uint16    TIF:1;         // 15    中断标志  Interrupt flag CPU定时器中断标志 计数器减到0置1 也可以写1清0 写0无效
};

union TCR_REG {
    Uint16           all;
    struct TCR_BITS  bit;
};

//
// TPR: Pre-scale low bit definitions  预分频低位定义
//
struct  TPR_BITS {         // bits  description 定时器预订标寄存器
    Uint16     TDDR:8;     // 7:0  (TDDR+1)*SYSCLKOUT周期后TIM-1  定时器分频寄存器   Divide-down low 
    Uint16     PSC:8;      // 15:8 每个SYSCLKOUT减1,到0装载TDDR  定时器预订标计数器 Prescale counter low 
};

union TPR_REG { // 定时器预订标寄存器
   Uint16           all;
   struct TPR_BITS  bit;
};

//
// TPRH: Pre-scale high bit definitions 预分频高位定义
//
struct  TPRH_BITS {          // bits  description
    Uint16     TDDRH:8;      // 7:0  定时器分频寄存器 Divide-down high 
    Uint16     PSCH:8;       // 15:8  定时器预订标计数器 Prescale counter high 
};

union TPRH_REG {
    Uint16           all;
    struct TPRH_BITS bit;
};

//
// TIM, TIMH: Timer register definitions
// (TDDRH:TDDR)+1个SYSCLKOUT 时钟周期 --->  定时器分频值
// 减到0产生中断 重新装载周期值 PRDH:PRD
struct TIM_REG { // 定时器计数器  每经过TDDRH:TDDR的分频值，定时器计数器减1 
    Uint16  LSW; // 16-bits low CPU定时计数器的低16位
    Uint16  MSW; // 16-bits high CPU定时计数器的高16位
};

union TIM_GROUP { 
    Uint32          all;
    struct TIM_REG  half;
};

//
// PRD, PRDH: Period register definitions 周期寄存器定义
// 重新装载位  如果TCR的TRB位为1，定时器计数器减到0后，重新装载周期值
struct PRD_REG { // 定时器周期寄存器
    Uint16  LSW; // 16-bits low 定时器周期寄存器低16位
    Uint16  MSW; // 16-bits high 定时器周期寄存器高16位
};

union PRD_GROUP { // 定时器周期寄存器组
    Uint32          all;
    struct PRD_REG  half;
};

//
// CPU Timer Register File 定时器寄存器文件
//
struct CPUTIMER_REGS {  // 32位定时器寄存器
    union TIM_GROUP TIM;   // Timer counter register 定时器计数寄存器
    union PRD_GROUP PRD;   // Period register 周期寄存器
    union TCR_REG   TCR;   // Timer control register 定时器控制寄存器
    Uint16          rsvd1; // reserved 保留
    union TPR_REG   TPR;   // Timer pre-scale low 预分频低位
    union TPRH_REG  TPRH;  // Timer pre-scale high 预分频高位
};

//
// CPU Timer Support Variables 定时器支持变量
//
struct CPUTIMER_VARS {
    volatile struct  CPUTIMER_REGS  *RegsAddr; // 指向定时器0的地址 Pointer to register structure 寄存器结构指针
    Uint32    InterruptCount;  // CPU Timer interrupt counter 定时器中断计数器
    float   CPUFreqInMHz; // CPU frequency in MHz CPU频率（MHz）
    float   PeriodInUSec; // Period in uSeconds 周期（微秒）
};

//
// Function prototypes and external definitions
//
void InitCpuTimers(void); // Initialize CpuTimers 初始化定时器
void ConfigCpuTimer(struct CPUTIMER_VARS *Timer, float Freq, float Period); // Configure CpuTimer 配置定时器

extern volatile struct CPUTIMER_REGS CpuTimer0Regs; // CpuTimer0 register 文件
extern struct CPUTIMER_VARS CpuTimer0; // CpuTimer0 support variables 支持变量

//
// CpuTimer 1 and CpuTimer2 are reserved for DSP BIOS & other RTOS. 1或0定时器保留给DSP BIOS和其他RTOS
// Comment out CpuTimer1 and CpuTimer2 if using DSP BIOS or other RTOS 如果使用DSP BIOS或其他RTOS，请注释掉CpuTimer1和CpuTimer2
//
extern volatile struct CPUTIMER_REGS CpuTimer1Regs;
extern volatile struct CPUTIMER_REGS CpuTimer2Regs;

extern struct CPUTIMER_VARS CpuTimer1;
extern struct CPUTIMER_VARS CpuTimer2;

//
// Defines for useful Timer Operations:
//

//
// Start Timer
//
#define StartCpuTimer0()   CpuTimer0Regs.TCR.bit.TSS = 0 // 启动定时器0 定时器控制寄存器的时钟控制位

//
// Stop Timer
//
#define StopCpuTimer0()   CpuTimer0Regs.TCR.bit.TSS = 1 // 停止定时器0 TCR_BITS的时钟控制位

//
// Reload Timer With period Value
//
#define ReloadCpuTimer0() CpuTimer0Regs.TCR.bit.TRB = 1  // 重载定时器0

//
// Read 32-Bit Timer Value
//
#define ReadCpuTimer0Counter() CpuTimer0Regs.TIM.all // 读取定时器0的计数值

//
// Read 32-Bit Period Value
//
#define ReadCpuTimer0Period() CpuTimer0Regs.PRD.all // 读取定时器0的周期值

//
// CpuTimer 1 and CpuTimer2 are reserved for DSP BIOS & other RTOS
// Do not use these two timers if you ever plan on integrating
// DSP-BIOS or another realtime OS.
//
// For this reason, comment out the code to manipulate these two timers
// if using DSP-BIOS or another realtime OS.
//

//
// Start Timer
//
#define StartCpuTimer1()   CpuTimer1Regs.TCR.bit.TSS = 0 // 启动定时器0 TCR_BITS的时钟控制位 
#define StartCpuTimer2()   CpuTimer2Regs.TCR.bit.TSS = 0 // 启动定时器2

//
// Stop Timer
//
#define StopCpuTimer1()   CpuTimer1Regs.TCR.bit.TSS = 1  // 停止定时器1 TCR_BITS的时钟控制位
#define StopCpuTimer2()   CpuTimer2Regs.TCR.bit.TSS = 1 // 停止定时器2

//
// Reload Timer With period Value
//
#define ReloadCpuTimer1() CpuTimer1Regs.TCR.bit.TRB = 1 // 重载定时器1
#define ReloadCpuTimer2() CpuTimer2Regs.TCR.bit.TRB = 1 // 重载定时器2

//
// Read 32-Bit Timer Value
//
#define ReadCpuTimer1Counter() CpuTimer1Regs.TIM.all // 读取定时器1的计数值
#define ReadCpuTimer2Counter() CpuTimer2Regs.TIM.all // 读取定时器2的计数值

//
// Read 32-Bit Period Value
//
#define ReadCpuTimer1Period() CpuTimer1Regs.PRD.all // 读取定时器1的周期值
#define ReadCpuTimer2Period() CpuTimer2Regs.PRD.all // 读取定时器2的周期值

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of DSP2833x_CPU_TIMERS_H definition

//
// End of file
//

