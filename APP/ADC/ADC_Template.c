/*
 * ADC_Template.c
 *
 *  Created on: 2024年3月5日
 *      Author:
 */

#include "ADC_Template.h"
/**
  *   顺序采样 + 级联模式
  *   顺序采样 + 双排序模式
  *   同步采样 + 级联模式
  *   同步采样 + 双排序模式
 */

/**
 *
 *  顺序采样 +级联模式->直接开启SOC_SEQ1序列转换器
 *
 */
void ConfADCInit0(void){
        InitAdc();        //校准和给电路上电 需要放到最前面  给模拟电路外围电路上电
        AdcRegs.ADCTRL1.bit.CPS=0;           //  对 HISPCLK 进行不分频
        AdcRegs.ADCTRL3.bit.ADCCLKPS=3;      // 对 ADCCLK 进行3分频 得到25MHz
        AdcRegs.ADCTRL1.bit.ACQ_PS=0xf;      // 16个ADC时钟周期  采样时间是 (1/25MHz)x(ACQ_PS+1)
        AdcRegs.ADCREFSEL.bit.REF_SEL = 0;   // 内部参考电压选择

        AdcRegs.ADCTRL3.bit.SMODE_SEL = 0; // 顺序采样
//      AdcRegs.ADCTRL3.bit.SMODE_SEL = 1; // 同步采样

      AdcRegs.ADCTRL1.bit.SEQ_CASC = 1;  // 级联模式
//    AdcRegs.ADCTRL1.bit.SEQ_CASC = 0;  // 双序列模式

       AdcRegs.ADCMAXCONV.bit.MAX_CONV1=0x5; // 选择2个通道 设置 0x0-0x15  表示1-16通道
//     AdcRegs.ADCMAXCONV.bit.MAX_CONV2=0x1;
       AdcRegs.ADCCHSELSEQ1.bit.CONV00=0x0; //  开启 A0通道
       AdcRegs.ADCCHSELSEQ1.bit.CONV01=0x8; //  开启 B0通道
       AdcRegs.ADCCHSELSEQ1.bit.CONV02=0x1; //  开启 A1通道
       AdcRegs.ADCCHSELSEQ1.bit.CONV03=0x9; //  开启 B1通道
       // 顺序 + 级联模式必须是连续的转换序列 跨序列不行
//       AdcRegs.ADCCHSELSEQ3.bit.CONV08=0x2; //  开启 A2通道 这个读不到
//       AdcRegs.ADCCHSELSEQ3.bit.CONV09=0x10; //  开启 B2通道 这个读不到

        AdcRegs.ADCTRL1.bit.CONT_RUN=1; // 选择连续模式 1 连续 连续模式适合级联
        AdcRegs.ADCTRL2.bit.SOC_SEQ1=1;
}



/**
 *  顺序采样 + 双排序模式的配置方法
 *
 */
void ConfADCInit1(void){
        InitAdc();        //校准和给电路上电 需要放到最前面  给模拟电路外围电路上电
        AdcRegs.ADCTRL1.bit.CPS=0;           //  对 HISPCLK 进行不分频
        AdcRegs.ADCTRL3.bit.ADCCLKPS=3;      // 对 ADCCLK 进行3分频 得到25MHz
        AdcRegs.ADCTRL1.bit.ACQ_PS=0xf;      // 16个ADC时钟周期  采样时间是 (1/25MHz)x(ACQ_PS+1)
        AdcRegs.ADCREFSEL.bit.REF_SEL = 0;   // 内部参考电压选择

        AdcRegs.ADCTRL3.bit.SMODE_SEL = 0; // 顺序采样      两个采样保持器
//      AdcRegs.ADCTRL3.bit.SMODE_SEL = 1; // 同步采样
//      AdcRegs.ADCTRL1.bit.SEQ_CASC = 1;  // 级联模式
        AdcRegs.ADCTRL1.bit.SEQ_CASC = 0;  // 双序列模式

        AdcRegs.ADCMAXCONV.bit.MAX_CONV1=0x1; // 选择1个通道 设置 0x0-0x15  表示1-16通道
        AdcRegs.ADCMAXCONV.bit.MAX_CONV2=0x0; // 选择1个通道 设置 0x0-0x15  表示1-16通道

        AdcRegs.ADCCHSELSEQ1.bit.CONV00=0x1; //  选择了A1通道
        AdcRegs.ADCCHSELSEQ1.bit.CONV01=0x8; //  选择了B0通道
        AdcRegs.ADCCHSELSEQ3.bit.CONV08=0x0; //  选择了A0通道 两个序列

        AdcRegs.ADCTRL1.bit.CONT_RUN=0; // 选择读取停止模式

}
/**
 *
 * 顺序采样 + 双排序模式的读取方法
 */
void  Read_ADCValue1(void){
    if(AdcRegs.ADCST.bit.INT_SEQ1==1   ){ //当1序列读取完成
        AdcRegs.ADCST.bit.INT_SEQ1_CLR=1; //清除中断标志位 会让SOC_SEQ1=0
          AdcRegs.ADCTRL2.bit.RST_SEQ1=1; // 重置1排序器
         AdcRegs.ADCTRL2.bit.SOC_SEQ2=1; // 在开始读取2序列
          if(AdcRegs.ADCST.bit.INT_SEQ2 == 1  ){ //当2序列读取完成
           AdcRegs.ADCST.bit.INT_SEQ2_CLR=1; //清除2中断标志位
           AdcRegs.ADCTRL2.bit.RST_SEQ2=1; // 重置1排序器
            }
    }
    AdcRegs.ADCTRL2.bit.SOC_SEQ1=1;
}


/**
 *
 *  同步采样 +级联模式->直接开启SOC_SEQ1序列转换器
 */
void ConfADCInit2(void){
        InitAdc();        //校准和给电路上电 需要放到最前面  给模拟电路外围电路上电
        AdcRegs.ADCTRL1.bit.CPS=0;           //  对 HISPCLK 进行不分频
        AdcRegs.ADCTRL3.bit.ADCCLKPS=3;      // 对 ADCCLK 进行3分频 得到25MHz
        AdcRegs.ADCTRL1.bit.ACQ_PS=0xf;      // 16个ADC时钟周期  采样时间是 (1/25MHz)x(ACQ_PS+1)
        AdcRegs.ADCREFSEL.bit.REF_SEL = 0;   // 内部参考电压选择

//    AdcRegs.ADCTRL3.bit.SMODE_SEL = 0; // 顺序采样      两个采样保持器
      AdcRegs.ADCTRL3.bit.SMODE_SEL = 1; // 同步采样

      AdcRegs.ADCTRL1.bit.SEQ_CASC = 1;  // 级联模式
//    AdcRegs.ADCTRL1.bit.SEQ_CASC = 0;  // 双序列模式

       AdcRegs.ADCMAXCONV.bit.MAX_CONV1=0x1; // 选择2个通道 设置 0x0-0x15  表示1-16通道
//     AdcRegs.ADCMAXCONV.bit.MAX_CONV2=0x1;
       AdcRegs.ADCCHSELSEQ1.bit.CONV00=0x0; //  会开启 AO通道 和 B0 通道
       AdcRegs.ADCCHSELSEQ1.bit.CONV01=0x1; //  开启   A1通道 和 B1 通道


        AdcRegs.ADCTRL1.bit.CONT_RUN=1; // 选择连续模式 1 连续
        AdcRegs.ADCTRL2.bit.SOC_SEQ1=1;
}
/**
 *
 * 同步采样 + 级联排序模式的读取方法
 */
void Read_ADCValue2(){
//    if(AdcRegs.ADCST.bit.INT_SEQ1 ==1){
//        AdcRegs.ADCST.bit.INT_SEQ1_CLR =1;
//    }

}


/**
 *  同步采样 S/H-A & S/H-B   +  双排序模式的配置方法 SEQ1 & SEQ2
 *
 */
void ConfADCInit3(void){
        InitAdc();        //校准和给电路上电 需要放到最前面  给模拟电路外围电路上电
        AdcRegs.ADCTRL1.bit.CPS=0;           //  对 HISPCLK 进行不分频
        AdcRegs.ADCTRL3.bit.ADCCLKPS=3;      // 对 ADCCLK 进行3分频 得到25MHz
        AdcRegs.ADCTRL1.bit.ACQ_PS=0xf;      // 16个ADC时钟周期  采样时间是 (1/25MHz)x(ACQ_PS+1)
        AdcRegs.ADCREFSEL.bit.REF_SEL = 0;   // 内部参考电压选择

//      AdcRegs.ADCTRL3.bit.SMODE_SEL = 0; // 顺序采样      两个采样保持器
        AdcRegs.ADCTRL3.bit.SMODE_SEL = 1; // 同步采样
//      AdcRegs.ADCTRL1.bit.SEQ_CASC = 1;  // 级联模式
        AdcRegs.ADCTRL1.bit.SEQ_CASC = 0;  // 双序列模式

        AdcRegs.ADCMAXCONV.bit.MAX_CONV1=0x1; // 选择1个通道 设置 0x0-0x15  表示1-16通道
//      AdcRegs.ADCMAXCONV.bit.MAX_CONV2=0x0; // 选择1个通道 设置 0x0-0x15  表示1-16通道
        AdcRegs.ADCCHSELSEQ1.bit.CONV00=0x1; //  选择了A1通道 选择了B1通道
        AdcRegs.ADCCHSELSEQ1.bit.CONV01=0x2; //  选择了A2通道 选择了B2通道

        AdcRegs.ADCTRL1.bit.CONT_RUN=0; // 选择读取停止模式
}

/**
 *
 * 同步采样 + 双排序模式的读取方法
 */
void  Read_ADCValue3(void){
    if(AdcRegs.ADCST.bit.INT_SEQ1==1   ){ //当1序列读取完成
         AdcRegs.ADCST.bit.INT_SEQ1_CLR=1; //清除中断标志位 会让SOC_SEQ1=0
         AdcRegs.ADCTRL2.bit.RST_SEQ1=1; // 重置1排序器
         AdcRegs.ADCTRL2.bit.SOC_SEQ2=1; // 在开始读取2序列
          if(AdcRegs.ADCST.bit.INT_SEQ2 == 1  ){ //当2序列读取完成
           AdcRegs.ADCST.bit.INT_SEQ2_CLR=1; //清除2中断标志位
           AdcRegs.ADCTRL2.bit.RST_SEQ2=1; // 重置1排序器
            }
    }
    AdcRegs.ADCTRL2.bit.SOC_SEQ1=1;
}



