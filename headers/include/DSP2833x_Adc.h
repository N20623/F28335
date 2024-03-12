// TI File $Revision: /main/1 $
// Checkin $Date: August 18, 2006   13:51:50 $
//###########################################################################
//
// FILE:   DSP2833x_Adc.h
//
// TITLE:  DSP2833x Device ADC Register Definitions.
//  ADC 寄存器定义
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

#ifndef DSP2833x_ADC_H
#define DSP2833x_ADC_H

#ifdef __cplusplus
extern "C" {
#endif

//
// ADC Individual Register Bit Definitions: ADC初始化寄存器位定义
//
struct ADCTRL1_BITS {     // bits  description 16位
    Uint16  rsvd1:4;      // 3:0   reserved 3:0保留
    Uint16  SEQ_CASC:1;   // 4  0 双排序 ， 1 级联模式   Cascaded sequencer mode 4  排序模式选择 0：双排序器模式 两个 8---1：级联排序器模式 一个16
    Uint16  SEQ_OVRD:1;   // 5   排序器覆盖模式  Sequencer override    排序器覆盖模式 0：转换MAX_CONVn通道后 排序器指针复位到初始 1 最后一个所有排序状态后 排序器复位到初始状态
    Uint16  CONT_RUN:1;   // 6  运行方式 0 转换完成后等待触发才开始下一次 1 转换完成，立即开始下一次   Continuous run
    Uint16  CPS:1;        // 7  对外设时钟HSPCLK分频 0：/1 1：/2   ADC core clock pre-scalar 转换时间预定标器 对外设时钟HSPCLK分频 0：/1 1：/2
    Uint16  ACQ_PS:4;     // 11:8 采集为几个ADC时钟周期 同时决定了采样开关闭合的时间 Acquisition window size    采样时间选择 控制SOC的脉冲宽度
    Uint16  SUSMOD:2;     // 13:12 仿真挂起模式 Emulation suspend mode 仿真挂起模式 00 仿真挂起被忽略 01 当前排序完成后与其他逻辑立即停止工作 锁存最终结果更新状态 11 仿真挂起 排序与其他逻辑立即停止
    Uint16  RESET:1;      // 14    ADC reset ADC软件复位
    Uint16  rsvd2:1;      // 15    reserved 保留
};

union ADCTRL1_REG { // ADC控制寄存器1
   Uint16                all;
   struct ADCTRL1_BITS   bit;
};

struct ADCTRL2_BITS {         // bits  description  ACDC2寄存器位定义
    Uint16  EPWM_SOCB_SEQ2:1; // 0     EPWM compare B SOC mask for SEQ2 的ePWM SOCA 屏蔽位 0 ePWM 的触发信号不能启动SEQ2 1 ePWM的触发信号可以启动SEQ2 
    Uint16  rsvd1:1;          // 1     reserved 保留
    Uint16  INT_MOD_SEQ2:1;   // 2     SEQ2 Interrupt mode SEQ2中断模式 每隔SEQ2结束，触发INT_SEQ2中断 可以通过在中断程序中复位RST_SEQn
    Uint16  INT_ENA_SEQ2:1;   // 3     SEQ2 Interrupt enable SEQ2中断使能 1：使能 0：禁止
    Uint16  rsvd2:1;          // 4     reserved 保留
    Uint16  SOC_SEQ2:1;       // 5     Start of conversion for SEQ2 SEQ2转换开始 该位写1 立即复位SEQ2 退出正在转换的序列
    Uint16  RST_SEQ2:1;       // 6     Reset SEQ2 复位SEQ2 如果CONV_RUN没有置位 SEQ_CNTR继续为0 为在下一次SOC时 使用RST_SEQ 复位排序
    Uint16  EXT_SOC_SEQ1:1;   // 7     External start of conversion for SEQ1 SEQ1转换的外部开始 1外部ADCSOC信号启动ADC自动转换
    Uint16  EPWM_SOCA_SEQ1:1; // 8     EPWM compare B SOC mask for SEQ1的ePWM SOCA 屏蔽位 0 ePWM 的触发信号不能启动SEQ1 1 ePWM的触发信号可以启动SEQ1    
    Uint16  rsvd3:1;          // 9     reserved 保留
    Uint16  INT_MOD_SEQ1:1;   // 10     可以通过在中断程序中复位RST_SEQn   SEQ1 Interrupt mode SEQ1中断模式 0： 每个seq1结束时 INT SEQ1置位  1：每隔个SEQ1结束时 INT SEQ1置位
    Uint16  INT_ENA_SEQ1:1;   // 11    SEQ1中断使能 1：使能 0：禁止    SEQ1 Interrupt enable
    Uint16  rsvd4:1;          // 12    reserved 保留
    Uint16  SOC_SEQ1:1;       // 13  SEQ1的启动转换触发   Start of conversion trigger for SEQ1
    Uint16  RST_SEQ1:1;       // 14  复位排序器 该位写1 立即复位SEQ1 退出正在转换的序列  Restart sequencer 1
    Uint16  EPWM_SOCB_SEQ:1;  // 15  级联排序器使能ePWM SOCB 1有效 0无效  EPWM compare B SOC enable
};

union ADCTRL2_REG { // ADC控制寄存器2
   Uint16                all;
   struct ADCTRL2_BITS   bit;
};

struct ADCASEQSR_BITS {       // bits ADC自动序列状态寄存器  description ADC Auto Sequence Status Register
    Uint16  SEQ1_STATE:4;     // 3:0  SEQ1 state是seq1的指针  SEQ1 state SEQ1状态
    Uint16  SEQ2_STATE:3;     // 6:4  SEQ2 state是seq2的指针  SEQ2 state SEQ2状态
    Uint16  rsvd1:1;          // 7      reserved 保留
    Uint16  SEQ_CNTR:4;       // 11:8  开始时值是MAX_CONV的值 每次自动转换减1 Sequencing counter status  顺序计数器状态
    Uint16  rsvd2:4;          // 15:12  reserved   保留
};

union ADCASEQSR_REG { // ADC自动定序状态寄存器
    Uint16                 all;
    struct ADCASEQSR_BITS  bit;
};
/***
 *  双排序模式 AdcRegs.ADCMAXCONV.all=0x0033; //表示每个排序器4个 共8个
 *  级联模式  AdcRegs.ADCMAXCONV.all=0x0007; // 表示每个排序器8个 共16个
 */
struct ADCMAXCONV_BITS {      // bits  description   ADC最大转换数通道数 seq1运行时使用MAX_CONV1[2:0]---seq2运行时使用MAX_CONV2[2:0]---seq运行时使用MAX_CONV1[3:0] 
    Uint16  MAX_CONV1:4;      // 3:0 最大转换数  MAX_CONV1  Max number of conversions
    Uint16  MAX_CONV2:3;      // 6:4    最大转换数 MAX_CONV2  Max number of conversions
    Uint16  rsvd1:9;          // 15:7  reserved 
};

union ADCMAXCONV_REG { // ADC最大转换数寄存器
    Uint16                  all;
    struct ADCMAXCONV_BITS  bit;
};

struct ADCCHSELSEQ1_BITS {    // bits   description  ADCINA0~ADCINA7 --0000~0111  ADCINB0~ADCINB7 --1000~1111 
    Uint16  CONV00:4;         // 3:0    Conversion selection 00 seq1转换选择00
    Uint16  CONV01:4;         // 7:4    Conversion selection 01 seq1转换选择01
    Uint16  CONV02:4;         // 11:8   Conversion selection 02 seq1转换选择02
    Uint16  CONV03:4;         // 15:12  Conversion selection 03 seq1转换选择03
};

union  ADCCHSELSEQ1_REG{ // ADC信道选择定序控制寄存器1
    Uint16                    all;
    struct ADCCHSELSEQ1_BITS  bit;
};

struct ADCCHSELSEQ2_BITS {    // bits   description
    Uint16  CONV04:4;         // 3:0 0004   Conversion selection 04 seq2转换选择04
    Uint16  CONV05:4;         // 7:4    Conversion selection 05 seq2转换选择05
    Uint16  CONV06:4;         // 11:8   Conversion selection 06 seq2转换选择06
    Uint16  CONV07:4;         // 15:12  Conversion selection 07 seq2转换选择07
};

union  ADCCHSELSEQ2_REG{ // ADC信道选择定序控制寄存器2
    Uint16                    all;
    struct ADCCHSELSEQ2_BITS  bit;
};

struct ADCCHSELSEQ3_BITS {    // bits   description
    Uint16  CONV08:4;         // 3:0    Conversion selection 08 seq3转换选择08
    Uint16  CONV09:4;         // 7:4    Conversion selection 09 seq3转换选择09
    Uint16  CONV10:4;         // 11:8   Conversion selection 10 seq3转换选择10
    Uint16  CONV11:4;         // 15:12  Conversion selection 11 seq3转换选择11
};

union  ADCCHSELSEQ3_REG{ // ADC信道选择定序控制寄存器3
    Uint16                    all;
    struct ADCCHSELSEQ3_BITS  bit;
};

struct ADCCHSELSEQ4_BITS {    // bits   description
    Uint16  CONV12:4;         // 3:0    Conversion selection 12 seq4转换选择12
    Uint16  CONV13:4;         // 7:4    Conversion selection 13 seq4转换选择13
    Uint16  CONV14:4;         // 11:8   Conversion selection 14 seq4转换选择14
    Uint16  CONV15:4;         // 15:12  Conversion selection 15 seq4转换选择15
};

union  ADCCHSELSEQ4_REG { // ADC信道选择定序控制寄存器4
    Uint16                    all;
    struct ADCCHSELSEQ4_BITS  bit;
};

struct ADCTRL3_BITS {         // bits   description 使用外部参考电压 必须在上电之前
    Uint16   SMODE_SEL:1;     // 0  两个采样保持器 S/H-A S/H-B   采样模式选择 0 顺序采样 1同步采样  Sampling mode select (同步采样模式中的一对)
    Uint16   ADCCLKPS:4;      // 4:1  对ADCCLK进行分频   ADC core clock divider ADC核心时钟分频 1-15 [0000-1111]
    Uint16   ADCPWDN:1;       // 5    关闭    0  |掉电 0   |上电   1   ADC powerdown ADC电源控制 0 除带隙与参考电路外的ADC其他模拟电路掉电 1除带隙与参考电路外的ADC其他模拟电路上电
    Uint16   ADCBGRFDN:2;     // 7:6        0 0  |  1 1   |    1  1    ADC bandgap/ref power down ADC带隙和参考电源控制 00 带隙与参考电路掉电 11 带隙参考电路上电
    Uint16   rsvd1:8;         // 15:8   reserved 保留
}; 

union  ADCTRL3_REG {  //ADC控制3寄存器
    Uint16                all;
    struct ADCTRL3_BITS   bit;
};

struct ADCST_BITS {           // bits   description ADC状态寄存器
    Uint16   INT_SEQ1:1;      // 0 所有转换完成 发生SEQ1中断 置1   SEQ1 Interrupt flag   SEQ1中断标志
    Uint16   INT_SEQ2:1;      // 1 所有转换完成 发生SEQ2中断 置1   SEQ2 Interrupt flag  SEQ2中断标志
    Uint16   SEQ1_BSY:1;      // 2  SEQ1-正在转换 忙状态 1忙 0空闲   SEQ1 busy status SEQ1
    Uint16   SEQ2_BSY:1;      // 3  SEQ2-正在转换 忙状态  SEQ2 busy status SEQ2
    Uint16   INT_SEQ1_CLR:1;  // 4  SEQ1中断清除 转换完成清除中断 SEQ1 Interrupt clear
    Uint16   INT_SEQ2_CLR:1;  // 5  SEQ2中断清除 转换完成清除中断 Interrupt clear SEQ2
    Uint16   EOS_BUF1:1;      // 6  SEQ1的排序缓冲结束   End of sequence buffer1
    Uint16   EOS_BUF2:1;      // 7  SEQ2的排序缓冲结束   End of sequence buffer2
    Uint16   rsvd1:8;         // 15:8   reserved
};
                           
union  ADCST_REG {            
    Uint16             all;    
    struct ADCST_BITS  bit;    
};                           

struct ADCREFSEL_BITS {       // bits   description 参考选择寄存器
	Uint16   rsvd1:14;        // 13:0   reserved  
	Uint16   REF_SEL:2;       // 15:14  00 内部 默认；01 外部 2.048V ；10 外部 1.500V ；11 外部 1.024V        Reference select 参考选择  
};
union ADCREFSEL_REG {        // ADC参考选择寄存器
	Uint16		all;
	struct ADCREFSEL_BITS bit;
};

struct ADCOFFTRIM_BITS{       // bits   description 偏移调整
	int16	OFFSET_TRIM:9;    // 8:0    Offset Trim   LSB中的偏移调整，两者的补充格式 -256~255
	Uint16	rsvd1:7;          // 15:9   reserved
};

union ADCOFFTRIM_REG{
	Uint16		all;
	struct ADCOFFTRIM_BITS bit;
};

struct ADC_REGS {            // ADC寄存器定义  0x007100-0x00711F
    union ADCTRL1_REG      ADCTRL1;       //ADC Control 1 ADC控制1
    union ADCTRL2_REG      ADCTRL2;       //ADC Control 2 ADC控制2
    union ADCMAXCONV_REG   ADCMAXCONV;    //Max conversions ADC最大转换信道数寄存器
    union ADCCHSELSEQ1_REG ADCCHSELSEQ1;  // ADC信道选择定序控制寄存器1  同步模式MSB不起作用 Channel select sequencing control 1
    union ADCCHSELSEQ2_REG ADCCHSELSEQ2;  // ADC信道选择定序控制寄存器2  同步模式MSB不起作用  Channel select sequencing control 2
    union ADCCHSELSEQ3_REG ADCCHSELSEQ3;  // ADC信道选择定序控制寄存器3  同步模式MSB不起作用  Channel select sequencing control 3
    union ADCCHSELSEQ4_REG ADCCHSELSEQ4;  // ADC信道选择定序控制寄存器4  同步模式MSB不起作用  Channel select sequencing control 4
    union ADCASEQSR_REG    ADCASEQSR;     // ADC自动定列状态寄存器 Autosequence status register 
    Uint16                 ADCRESULT0;    //Conversion Result Buffer 0 转换结果缓冲区0
    Uint16                 ADCRESULT1;    //Conversion Result Buffer 1 转换结果缓冲区1
    Uint16                 ADCRESULT2;    //Conversion Result Buffer 2 转换结果缓冲区2
    Uint16                 ADCRESULT3;    //Conversion Result Buffer 3 转换结果缓冲区3
    Uint16                 ADCRESULT4;    //Conversion Result Buffer 4 转换结果缓冲区4
    Uint16                 ADCRESULT5;    //Conversion Result Buffer 5 转换结果缓冲区5
    Uint16                 ADCRESULT6;    //Conversion Result Buffer 6 转换结果缓冲区6
    Uint16                 ADCRESULT7;    //Conversion Result Buffer 7 转换结果缓冲区7
    Uint16                 ADCRESULT8;    //Conversion Result Buffer 8 转换结果缓冲区8
    Uint16                 ADCRESULT9;    //Conversion Result Buffer 9 转换结果缓冲区9
    Uint16                 ADCRESULT10;   //Conversion Result Buffer 10 转换结果缓冲区10
    Uint16                 ADCRESULT11;   //Conversion Result Buffer 11 转换结果缓冲区11
    Uint16                 ADCRESULT12;   //Conversion Result Buffer 12 转换结果缓冲区12
    Uint16                 ADCRESULT13;   //Conversion Result Buffer 13 转换结果缓冲区13
    Uint16                 ADCRESULT14;   //Conversion Result Buffer 14 转换结果缓冲区14
    Uint16                 ADCRESULT15;   //Conversion Result Buffer 15 转换结果缓冲区15
    union ADCTRL3_REG      ADCTRL3;       //ADC Control 3  ADC3控制
    union ADCST_REG        ADCST;         //ADC Status Register ADC状态寄存器
    Uint16				   rsvd1;
    Uint16                 rsvd2;
    union ADCREFSEL_REG    ADCREFSEL;     //ADC基准选择寄存器 Reference Select Register 
    union ADCOFFTRIM_REG   ADCOFFTRIM;    //ADC偏移调整寄存器 Offset Trim Register 
};
// origin = 0x000B00, length = 0x000010  end = 0x000B0F
struct ADC_RESULT_MIRROR_REGS // ADC结果镜像寄存器  ADC结果是双映射的
{
    Uint16                 ADCRESULT0;    // 0x000B00 Conversion Result Buffer 0 转换结果缓冲区0
    Uint16                 ADCRESULT1;    // 0x000B01 Conversion Result Buffer 1 转换结果缓冲区1
    Uint16                 ADCRESULT2;    // 0x000B02 Conversion Result Buffer 2 转换结果缓冲区2
    Uint16                 ADCRESULT3;    // 0x000B03 Conversion Result Buffer 3 转换结果缓冲区3
    Uint16                 ADCRESULT4;    // 0x000B04 Conversion Result Buffer 4 转换结果缓冲区4
    Uint16                 ADCRESULT5;    // 0x000B05 Conversion Result Buffer 5 转换结果缓冲区5
    Uint16                 ADCRESULT6;    // 0x000B06 Conversion Result Buffer 6 转换结果缓冲区6
    Uint16                 ADCRESULT7;    // 0x000B07 Conversion Result Buffer 7 转换结果缓冲区7
    Uint16                 ADCRESULT8;    // 0x000B08 Conversion Result Buffer 8 转换结果缓冲区8
    Uint16                 ADCRESULT9;    // 0x000B09 Conversion Result Buffer 9 转换结果缓冲区9
    Uint16                 ADCRESULT10;   // 0x000B0A Conversion Result Buffer 10 转换结果缓冲区10
    Uint16                 ADCRESULT11;   // 0x000B0B Conversion Result Buffer 11 转换结果缓冲区11
    Uint16                 ADCRESULT12;   // 0x000B0C Conversion Result Buffer 12 转换结果缓冲区12
    Uint16                 ADCRESULT13;   // 0x000B0D Conversion Result Buffer 13 转换结果缓冲区13
    Uint16                 ADCRESULT14;   // 0x000B0E Conversion Result Buffer 14 转换结果缓冲区14
    Uint16                 ADCRESULT15;   // 0x000B0F Conversion Result Buffer 15 转换结果缓冲区15
};

//
// ADC External References & Function Declarations:
//
extern volatile struct ADC_REGS AdcRegs; // ADC寄存器
extern volatile struct ADC_RESULT_MIRROR_REGS AdcMirror; // ADC结果镜像寄存器

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of DSP2833x_ADC_H definition

//
// End of file
//

