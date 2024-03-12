/*
 * ADC_Template.h
 *
 *  Created on: 2024年3月5日
 *      Author: Lenovo
 *   File   ADC_Template.h
 */


#ifndef ADC_TEMPLATE_H
#define ADC_TEMPLATE_H

#include "DSP2833x_Device.h"
#include "DSP2833x_Examples.h"
// 顺序和同步 是因为有两个 S/H-A S/H-B 采样和保持器  适合同一时刻采集两个通道

// 级联模式 和 双排序模式
// 级联模式只需要开启SEQ1
// 双排序需要开启SEQ1 和 SEQ2且必须读取完SEQ1才开始SEQ2 而且SEQ2的触发只有 软件 和 ePWM开启两种方式

void ConfADCInit0(void);  // 顺序采样 +级联模式
void Read_ADCValue0(void);

void ConfADCInit1(void); // 顺序采样+ 双排序
void Read_ADCValue1(void);

void ConfADCInit2(void); // 同步采样 + 级联模式
void Read_ADCValue1(void);

void ConfADCInit3(void); // 同步采样+ 双排序模式
void Read_ADCValue3(void);


#endif /*_ADC_TEMPLATE_*/
