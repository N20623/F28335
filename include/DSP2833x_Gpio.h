// TI File $Revision: /main/4 $
// Checkin $Date: November 15, 2007   09:58:53 $
//###########################################################################
//
// FILE:   DSP2833x_Gpio.h
//
// TITLE:  DSP2833x General Purpose I/O Definitions.
//
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

#ifndef DSP2833x_GPIO_H
#define DSP2833x_GPIO_H


#ifdef __cplusplus
extern "C" {
#endif

//
// GPIO A control register bit definitions GPIOA 控制寄存器位定义
//
struct GPACTRL_BITS {         // bits   description SYSCLKOUT时钟周期x 2(K=00~FF)
    Uint16 QUALPRD0:8;        // 7:0   GPIO0-GPIO7引脚特定的采样周期  00 SYSCLKOUT时钟周期x2(K=00~FF)   Qual period
    Uint16 QUALPRD1:8;        // 15:8  GPIO8-GPIO15引脚特定的采样周期 01 SYSCLKOUT时钟周期x2(K=00~FF)  Qual period
    Uint16 QUALPRD2:8;        // 23:16  GPIO16-GPIO23引脚特定的采样周期 FF SYSCLKOUT时钟周期x2(K=00~FF)  Qual period
    Uint16 QUALPRD3:8;        // 31:24  GPIO24-GPIO31引脚特定的采样周期   SCLKOUT时钟周期x2(K=00~FF) Qual period
};

union GPACTRL_REG {
    Uint32              all;
    struct GPACTRL_BITS bit;
};

//
// GPIO B control register bit definitions GPIOB 控制寄存器位定义
//
struct GPBCTRL_BITS {        // bits   description
    Uint16 QUALPRD0:8;        // 7:0   引脚特定的采样周期  SCLKOUT时钟周期x2(K=00~FF)  Qual period
    Uint16 QUALPRD1:8;        // 15:8  引脚特定的采样周期   SCLKOUT时钟周期x2(K=00~FF)  Qual period
    Uint16 QUALPRD2:8;        // 23:16  引脚特定的采样周期   SCLKOUT时钟周期x2(K=00~FF) Qual period
    Uint16 QUALPRD3:8;        // 31:24 引脚特定的采样周期    SCLKOUT时钟周期x2(K=00~FF)
};

union GPBCTRL_REG {
    Uint32              all;
    struct GPBCTRL_BITS bit;
};

//
// GPIO A Qual/MUX select register bit definitions GPIOA Qual/MUX选择寄存器位定义
//
struct GPA1_BITS {             // bits   description 设置引脚功能
    Uint16 GPIO0:2;            // 1:0   设置引脚功能        00 GPIO/io; 01 EPWM1A ;10被保留 11;被保留  GPIO0
    Uint16 GPIO1:2;            // 3:2    GPIO1 设置引脚功能
    Uint16 GPIO3:2;            // 7:6    GPIO3      设置引脚功能
    Uint16 GPIO2:2;            // 5:4    GPIO2      设置引脚功能
    Uint16 GPIO4:2;            // 9:8    GPIO4      设置引脚功能
    Uint16 GPIO5:2;            // 11:10  GPIO5      设置引脚功能
    Uint16 GPIO6:2;            // 13:12  GPIO6      设置引脚功能
    Uint16 GPIO7:2;            // 15:14  GPIO7      设置引脚功能
    Uint16 GPIO8:2;            // 17:16  GPIO8      设置引脚功能
    Uint16 GPIO9:2;            // 19:18  GPIO9      设置引脚功能
    Uint16 GPIO10:2;           // 21:20  GPIO10     设置引脚功能
    Uint16 GPIO11:2;           // 23:22  GPIO11     设置引脚功能
    Uint16 GPIO12:2;           // 25:24  GPIO12     设置引脚功能
    Uint16 GPIO13:2;           // 27:26  GPIO13     设置引脚功能
    Uint16 GPIO14:2;           // 29:28  GPIO14     设置引脚功能
    Uint16 GPIO15:2;           // 31:30  GPIO15     设置引脚功能
};

struct GPA2_BITS {             // bits   description
    Uint16 GPIO16:2;           // 1:0    GPIO16     设置引脚功能
    Uint16 GPIO17:2;           // 3:2    GPIO17     设置引脚功能
    Uint16 GPIO18:2;           // 5:4    GPIO18     设置引脚功能
    Uint16 GPIO19:2;           // 7:6    GPIO19     设置引脚功能
    Uint16 GPIO20:2;           // 9:8    GPIO20     设置引脚功能
    Uint16 GPIO21:2;           // 11:10  GPIO21     设置引脚功能
    Uint16 GPIO22:2;           // 13:12  GPIO22     设置引脚功能
    Uint16 GPIO23:2;           // 15:14  GPIO23     设置引脚功能
    Uint16 GPIO24:2;           // 17:16  GPIO24     设置引脚功能
    Uint16 GPIO25:2;           // 19:18  GPIO25     设置引脚功能
    Uint16 GPIO26:2;           // 21:20  GPIO26     设置引脚功能
    Uint16 GPIO27:2;           // 23:22  GPIO27     设置引脚功能
    Uint16 GPIO28:2;           // 25:24  GPIO28     设置引脚功能
    Uint16 GPIO29:2;           // 27:26  GPIO29     设置引脚功能
    Uint16 GPIO30:2;           // 29:28  GPIO30     设置引脚功能
    Uint16 GPIO31:2;           // 31:30  GPIO31     设置引脚功能
};

struct GPB1_BITS {             // bits   description
    Uint16 GPIO32:2;           // 1:0    GPIO32    设置引脚功能
    Uint16 GPIO33:2;           // 3:2    GPIO33    设置引脚功能
    Uint16 GPIO34:2;           // 5:4    GPIO34    设置引脚功能
    Uint16 GPIO35:2;           // 7:6    GPIO35    设置引脚功能
    Uint16 GPIO36:2;           // 9:8    GPIO36    设置引脚功能
    Uint16 GPIO37:2;           // 11:10  GPIO37    设置引脚功能
    Uint16 GPIO38:2;           // 13:12  GPIO38    设置引脚功能
    Uint16 GPIO39:2;           // 15:14  GPIO39    设置引脚功能
    Uint16 GPIO40:2;           // 17:16  GPIO40    设置引脚功能
    Uint16 GPIO41:2;           // 19:16  GPIO41    设置引脚功能
    Uint16 GPIO42:2;           // 21:20  GPIO42    设置引脚功能
    Uint16 GPIO43:2;           // 23:22  GPIO43    设置引脚功能
    Uint16 GPIO44:2;           // 25:24  GPIO44    设置引脚功能
    Uint16 GPIO45:2;           // 27:26  GPIO45    设置引脚功能
    Uint16 GPIO46:2;           // 29:28  GPIO46    设置引脚功能
    Uint16 GPIO47:2;           // 31:30  GPIO47    设置引脚功能
};

struct GPB2_BITS  {            // bits   description
    Uint16 GPIO48:2;           // 1:0    GPIO48    设置引脚功能
    Uint16 GPIO49:2;           // 3:2    GPIO49    设置引脚功能
    Uint16 GPIO50:2;           // 5:4    GPIO50    设置引脚功能
    Uint16 GPIO51:2;           // 7:6    GPIO51    设置引脚功能
    Uint16 GPIO52:2;           // 9:8    GPIO52    设置引脚功能
    Uint16 GPIO53:2;           // 11:10  GPIO53    设置引脚功能
    Uint16 GPIO54:2;           // 13:12  GPIO54    设置引脚功能
    Uint16 GPIO55:2;           // 15:14  GPIO55    设置引脚功能
    Uint16 GPIO56:2;           // 17:16  GPIO56    设置引脚功能
    Uint16 GPIO57:2;           // 19:18  GPIO57    设置引脚功能
    Uint16 GPIO58:2;           // 21:20  GPIO58    设置引脚功能
    Uint16 GPIO59:2;           // 23:22  GPIO59    设置引脚功能
    Uint16 GPIO60:2;           // 25:24  GPIO60    设置引脚功能
    Uint16 GPIO61:2;           // 27:26  GPIO61    设置引脚功能
    Uint16 GPIO62:2;           // 29:28  GPIO62    设置引脚功能
    Uint16 GPIO63:2;           // 31:30  GPIO63    设置引脚功能
};

struct GPC1_BITS {             // bits   description
    Uint16 GPIO64:2;           // 1:0    GPIO64 选择引脚的功能
    Uint16 GPIO65:2;           // 3:2    GPIO65 选择引脚的功能
    Uint16 GPIO66:2;           // 5:4    GPIO66 选择引脚的功能
    Uint16 GPIO67:2;           // 7:6    GPIO67 选择引脚的功能
    Uint16 GPIO68:2;           // 9:8    GPIO68 选择引脚的功能
    Uint16 GPIO69:2;           // 11:10  GPIO69 选择引脚的功能
    Uint16 GPIO70:2;           // 13:12  GPIO70 选择引脚的功能
    Uint16 GPIO71:2;           // 15:14  GPIO71 选择引脚的功能
    Uint16 GPIO72:2;           // 17:16  GPIO72 选择引脚的功能
    Uint16 GPIO73:2;           // 19:18  GPIO73 选择引脚的功能
    Uint16 GPIO74:2;           // 21:20  GPIO74 选择引脚的功能
    Uint16 GPIO75:2;           // 23:22  GPIO75 选择引脚的功能
    Uint16 GPIO76:2;           // 25:24  GPIO76 选择引脚的功能
    Uint16 GPIO77:2;           // 27:26  GPIO77 选择引脚的功能
    Uint16 GPIO78:2;           // 29:28  GPIO78 选择引脚的功能
    Uint16 GPIO79:2;           // 31:30  GPIO79 选择引脚的功能
};

struct GPC2_BITS {             // bits   description
    Uint16 GPIO80:2;           // 1:0    GPIO80 选择引脚的功能
    Uint16 GPIO81:2;           // 3:2    GPIO81 选择引脚的功能
    Uint16 GPIO82:2;           // 5:4    GPIO82 选择引脚的功能
    Uint16 GPIO83:2;           // 7:6    GPIO83 选择引脚的功能
    Uint16 GPIO84:2;           // 9:8    GPIO84 选择引脚的功能
    Uint16 GPIO85:2;           // 11:10  GPIO85 选择引脚的功能
    Uint16 GPIO86:2;           // 13:12  GPIO86 选择引脚的功能
    Uint16 GPIO87:2;           // 15:14  GPIO87 选择引脚的功能
    Uint16 rsvd:16;            // 31:16  reserved
};

union GPA1_REG {
    Uint32              all;
    struct GPA1_BITS    bit;
};

union GPA2_REG {
    Uint32              all;
    struct GPA2_BITS    bit;
};

union GPB1_REG {
    Uint32              all;
    struct GPB1_BITS    bit;
};

union GPB2_REG {
    Uint32              all;
    struct GPB2_BITS    bit;
};

union GPC1_REG {
    Uint32              all;
    struct GPC1_BITS    bit;
};

union GPC2_REG {
    Uint32              all;
    struct GPC2_BITS    bit;
};

//
// GPIO A DIR/TOGGLE/SET/CLEAR register bit definitions GPIOA 方向/翻转/置位/清除寄存器位定义
//
struct GPADAT_BITS {           // bits   description
    Uint16 GPIO0:1;            // 0      GPIO0
    Uint16 GPIO1:1;            // 1      GPIO1
    Uint16 GPIO2:1;            // 2      GPIO2
    Uint16 GPIO3:1;            // 3      GPIO3
    Uint16 GPIO4:1;            // 4      GPIO4
    Uint16 GPIO5:1;            // 5      GPIO5
    Uint16 GPIO6:1;            // 6      GPIO6
    Uint16 GPIO7:1;            // 7      GPIO7
    Uint16 GPIO8:1;            // 8      GPIO8
    Uint16 GPIO9:1;            // 9      GPIO9
    Uint16 GPIO10:1;           // 10     GPIO10
    Uint16 GPIO11:1;           // 11     GPIO11
    Uint16 GPIO12:1;           // 12     GPIO12
    Uint16 GPIO13:1;           // 13     GPIO13
    Uint16 GPIO14:1;           // 14     GPIO14
    Uint16 GPIO15:1;           // 15     GPIO15
    Uint16 GPIO16:1;           // 16     GPIO16
    Uint16 GPIO17:1;           // 17     GPIO17
    Uint16 GPIO18:1;           // 18     GPIO18
    Uint16 GPIO19:1;           // 19     GPIO19
    Uint16 GPIO20:1;           // 20     GPIO20
    Uint16 GPIO21:1;           // 21     GPIO21
    Uint16 GPIO22:1;           // 22     GPIO22
    Uint16 GPIO23:1;           // 23     GPIO23
    Uint16 GPIO24:1;           // 24     GPIO24
    Uint16 GPIO25:1;           // 25     GPIO25
    Uint16 GPIO26:1;           // 26     GPIO26
    Uint16 GPIO27:1;           // 27     GPIO27
    Uint16 GPIO28:1;           // 28     GPIO28
    Uint16 GPIO29:1;           // 29     GPIO29
    Uint16 GPIO30:1;           // 30     GPIO30
    Uint16 GPIO31:1;           // 31     GPIO31
};

struct GPBDAT_BITS {           // bits   description
    Uint16 GPIO32:1;           // 0      GPIO32
    Uint16 GPIO33:1;           // 1      GPIO33
    Uint16 GPIO34:1;           // 2      GPIO34
    Uint16 GPIO35:1;           // 3      GPIO35
    Uint16 GPIO36:1;           // 4      GPIO36
    Uint16 GPIO37:1;           // 5      GPIO37
    Uint16 GPIO38:1;           // 6      GPIO38
    Uint16 GPIO39:1;           // 7      GPIO39
    Uint16 GPIO40:1;           // 8      GPIO40
    Uint16 GPIO41:1;           // 9      GPIO41
    Uint16 GPIO42:1;           // 10     GPIO42
    Uint16 GPIO43:1;           // 11     GPIO43
    Uint16 GPIO44:1;           // 12     GPIO44
    Uint16 GPIO45:1;           // 13     GPIO45
    Uint16 GPIO46:1;           // 14     GPIO46
    Uint16 GPIO47:1;           // 15     GPIO47
    Uint16 GPIO48:1;           // 16     GPIO48
    Uint16 GPIO49:1;           // 17     GPIO49
    Uint16 GPIO50:1;           // 18     GPIO50
    Uint16 GPIO51:1;           // 19     GPIO51
    Uint16 GPIO52:1;           // 20     GPIO52
    Uint16 GPIO53:1;           // 21     GPIO53
    Uint16 GPIO54:1;           // 22     GPIO54
    Uint16 GPIO55:1;           // 23     GPIO55
    Uint16 GPIO56:1;           // 24     GPIO56
    Uint16 GPIO57:1;           // 25     GPIO57
    Uint16 GPIO58:1;           // 26     GPIO58
    Uint16 GPIO59:1;           // 27     GPIO59
    Uint16 GPIO60:1;           // 28     GPIO60
    Uint16 GPIO61:1;           // 29     GPIO61
    Uint16 GPIO62:1;           // 30     GPIO62
    Uint16 GPIO63:1;           // 31     GPIO63
};

struct GPCDAT_BITS {           // bits   description
    Uint16 GPIO64:1;           // 0      GPIO64
    Uint16 GPIO65:1;           // 1      GPIO65
    Uint16 GPIO66:1;           // 2      GPIO66
    Uint16 GPIO67:1;           // 3      GPIO67
    Uint16 GPIO68:1;           // 4      GPIO68
    Uint16 GPIO69:1;           // 5      GPIO69
    Uint16 GPIO70:1;           // 6      GPIO70
    Uint16 GPIO71:1;           // 7      GPIO71
    Uint16 GPIO72:1;           // 8      GPIO72
    Uint16 GPIO73:1;           // 9      GPIO73
    Uint16 GPIO74:1;           // 10     GPIO74
    Uint16 GPIO75:1;           // 11     GPIO75
    Uint16 GPIO76:1;           // 12     GPIO76
    Uint16 GPIO77:1;           // 13     GPIO77
    Uint16 GPIO78:1;           // 14     GPIO78
    Uint16 GPIO79:1;           // 15     GPIO79
    Uint16 GPIO80:1;           // 16     GPIO80
    Uint16 GPIO81:1;           // 17     GPIO81
    Uint16 GPIO82:1;           // 18     GPIO82
    Uint16 GPIO83:1;           // 19     GPIO83
    Uint16 GPIO84:1;           // 20     GPIO84
    Uint16 GPIO85:1;           // 21     GPIO85
    Uint16 GPIO86:1;           // 22     GPIO86
    Uint16 GPIO87:1;           // 23     GPIO87
    Uint16 rsvd1:8;            // 31:24  reserved
};

union GPADAT_REG {
    Uint32              all;
    struct GPADAT_BITS  bit;
};

union GPBDAT_REG {
    Uint32              all;
    struct GPBDAT_BITS  bit;
};

union GPCDAT_REG {
    Uint32              all;
    struct GPCDAT_BITS  bit;
};

//
// GPIO Xint1/XINT2/XNMI select register bit definitions GPIO Xint1/XINT2/XNMI选择寄存器位定义
//
struct GPIOXINT_BITS {        // bits   description
    Uint16 GPIOSEL:5;         // 4:0  选择GPIO中断输入源  Select GPIO interrupt input source 
    Uint16 rsvd1:11;          // 15:5   reserved
};

union GPIOXINT_REG {
    Uint16                all;
    struct GPIOXINT_BITS  bit;
};

struct GPIO_CTRL_REGS {  // GPIO 控制寄存器 0x6F0
    /************************************GPIOA*******************************************/
    /**
     *  A包括初始化 采样周期 多路选择 方向 上拉禁止
     *  B包括初始化 采样周期 多路选择 方向 上拉禁止
     *  C 包括多路选择 方向 上拉禁止
    */

    union  GPACTRL_REG  GPACTRL;   //GPIOA控制寄存器 GPIO A Control Register (GPIO0 to 31)    
    //
    // GPIO A Qualifier Select 1 Register (GPIO0 to 15) 通用输入输出A限定器选择寄存器1
    //
    union  GPA1_REG     GPAQSEL1; //周期由QUALPRD寄存器配置 00与时钟同步 01 3个采样周期 10 6个采样周期 11 不同步 GPIOA量化控制寄存器1
    
    //
    // GPIO A Qualifier Select 2 Register (GPIO16 to 31)
    //
    union  GPA2_REG     GPAQSEL2; // 00与时钟同步 01 3个采样周期 10 6个采样周期 11 不同步 GPIOA量化控制寄存器1 用来消除数字量IO引脚的干扰
    
    //
    // GPIO A Mux 1 Register (GPIO0 to 15) 通用输入输出A多路选择寄存器1
    //
    union  GPA1_REG     GPAMUX1; // 选择引脚的功能 GPIOA多路选择寄存器1
    //
    // GPIO A Mux 2 Register (GPIO16 to 31)
    //
    union  GPA2_REG     GPAMUX2; //选择引脚的功能  GPIOA多路选择寄存器1
    
    union  GPADAT_REG   GPADIR;    // 0输入 1输出 GPIOA方向寄存器 GPIO A Direction Register (GPIO0 to 31)
    
    //
    // GPIO A Pull Up Disable Register (GPIO0 to 31) 通用输入输出A上拉关闭寄存器
    //
    union  GPADAT_REG   GPAPUD;   // GPIOA   1 禁止内部上拉 0 使能内部上拉
    
    Uint32              rsvd1;

    /************************************GPIOB*******************************************/

    union  GPBCTRL_REG  GPBCTRL;   // GPIO B 控制寄存器 Control Register (GPIO32 to 63) 通用输入输出B控制寄存器    
    //
    // GPIO B Qualifier Select 1 Register (GPIO32 to 47)
    //
    union  GPB1_REG     GPBQSEL1; // GPIOB量化控制寄存器1  00与时钟同步 01 3个采样周期 10 6个采样周期 11 不同步   
    //
    // GPIO B Qualifier Select 2 Register (GPIO48 to 63)
    //
    union  GPB2_REG     GPBQSEL2;  // GPIOB量化控制寄存器2   00与时钟同步 01 3个采样周期 10 6个采样周期 11 不同步   
    union  GPB1_REG     GPBMUX1;   // GPIOB选择寄存器1 选择引脚的功能  GPIO B Mux 1 Register (GPIO32 to 47)
    union  GPB2_REG     GPBMUX2;   // GPIOB选择寄存器2 选择引脚的功能 GPIO B Mux 2 Register (GPIO48 to 63)
    union  GPBDAT_REG   GPBDIR;    // 0输入 1输出 GPIO B 方向选择寄存器  Direction Register (GPIO32 to 63)    
    //
    // GPIO B Pull Up Disable Register (GPIO32 to 63) 通用输入输出B上拉关闭寄存器
    //
    union  GPBDAT_REG   GPBPUD; //  GPIOB上拉禁止寄存器 1 禁止内部上拉 0 使能内部上拉
    Uint16              rsvd2[8];

    /************************************GPIOC*******************************************/

    union  GPC1_REG     GPCMUX1;   // GPIO C 选择寄存器1 选择引脚的功能  Mux 1 Register (GPIO64 to 79)
    union  GPC2_REG     GPCMUX2;   // GPIO C 选择寄存器2 选择引脚的功能 Mux 2 Register (GPIO80 to 95)
    union  GPCDAT_REG   GPCDIR;    // 0输入 1输出 GPIO C 方向寄存器 Direction Register (GPIO64 to 95)    
    //
    // GPIO C Pull Up Disable Register (GPIO64 to 95)
    //
    union  GPCDAT_REG   GPCPUD; //  GPIOC上拉禁止寄存器 

};

struct GPIO_DATA_REGS {
    union  GPADAT_REG       GPADAT;       // 读取0-31位的状态值 GPIO Data Register (GPIO0 to 31)
    
    //
    // GPIO Data Set Register (GPIO0 to 31)
    //
    union  GPADAT_REG       GPASET;      // 置位 0-31
    
    //
    // GPIO Data Clear Register (GPIO0 to 31)
    //
    union  GPADAT_REG       GPACLEAR;     // 复位 0-31
    
    //
    // GPIO Data Toggle Register (GPIO0 to 31)
    //
    union  GPADAT_REG       GPATOGGLE; // 信号翻转00-31
    
    union  GPBDAT_REG       GPBDAT;       // 读取32-63位的状态值 GPIO Data Register (GPIO32 to 63)
    
    //
    // GPIO Data Set Register (GPIO32 to 63)
    //
    union  GPBDAT_REG       GPBSET;
    
    //
    // GPIO Data Clear Register (GPIO32 to 63)
    //
    union  GPBDAT_REG       GPBCLEAR;

    //
    // GPIO Data Toggle Register (GPIO32 to 63)
    //
    union  GPBDAT_REG       GPBTOGGLE;
    
    union  GPCDAT_REG       GPCDAT;    //  读取64-95位的状态值 GPIO Data Register (GPIO64 to 95)
    union  GPCDAT_REG       GPCSET;    //   GPIO Data Set Register (GPIO64 to 95)
    
    //
    // GPIO Data Clear Register (GPIO64 to 95)
    //
    union  GPCDAT_REG       GPCCLEAR;  
    
    //
    // GPIO Data Toggle Register (GPIO64 to 95)
    //
    union  GPCDAT_REG       GPCTOGGLE;    
    Uint16                  rsvd1[8];
}; 
/**
 * XINT1，XINT2 和 XINT 中断可接受来自 GPIO0-GPIO31 引脚的输入
 *  XINT3–XINT7 中断可接受来自 GPIO32-GPIO63 引脚的输入
 *
 */
struct GPIO_INT_REGS {
    union  GPIOXINT_REG     GPIOXINT1SEL; //GPIO 0~31 外部中断源选择寄存器1 XINT1 GPIO Input Selection XINT1
    union  GPIOXINT_REG     GPIOXINT2SEL; //GPIO 0~31 外部中断源选择寄存器2 XINT2 GPIO Input Selection
    union  GPIOXINT_REG     GPIOXNMISEL;  //GPIO 0~31 不可屏蔽中断源选择寄存器 XNMI_Xint13 GPIO Input Selection XNMI_Xint13
    union  GPIOXINT_REG     GPIOXINT3SEL; //GPIO 32~63 外部中断源选择寄存器3 XINT3 GPIO Input Selection
    union  GPIOXINT_REG     GPIOXINT4SEL; //GPIO 32~63 外部中断源选择寄存器4 XINT4 GPIO Input Selection
    union  GPIOXINT_REG     GPIOXINT5SEL; //GPIO 32~63 外部中断源选择寄存器5 XINT5 GPIO Input Selection
    union  GPIOXINT_REG     GPIOXINT6SEL; //GPIO 32~63 外部中断源选择寄存器6 XINT6 GPIO Input Selection
    union  GPIOXINT_REG     GPIOXINT7SEL; //GPIO 32~63 外部中断源选择寄存器7 XINT7 GPIO Input Selection
    union  GPADAT_REG       GPIOLPMSEL;   //GPIO 0~31 唤醒低功耗模式源选择寄存器Low power modes GP I/O input select 低功耗模式GP I/O输入选择
};

//
// GPI/O External References & Function Declarations
//
extern volatile struct GPIO_CTRL_REGS GpioCtrlRegs;
extern volatile struct GPIO_DATA_REGS GpioDataRegs;
extern volatile struct GPIO_INT_REGS GpioIntRegs;

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of DSP2833x_GPIO_H definition

//
// End of file
//

