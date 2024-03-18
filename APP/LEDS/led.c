/*
 * led.c
 *
 *  Created on: 2024年3月15日
 *      Author: Lenovo
 */
#include "led.h"

void ConfigLeds(void){
    /**
     *  D1 GPIO68
     *  D2 GPIO67
     *  D3 GPIO66
     *  D4 GPIO65
     *  D5 GPIO64
     *  D6 GPIO10
     *  D7 GPIO11
     */
    EALLOW;
    GpioCtrlRegs.GPAMUX1.bit.GPIO10=0; // 设置为通用输入输出
    GpioCtrlRegs.GPADIR.bit.GPIO10=1;  // 设置为输出方向
    GpioCtrlRegs.GPAPUD.bit.GPIO10=1; // 开 关闭内部上拉 不影响输入低电平

    GpioCtrlRegs.GPADIR.bit.GPIO11=1; //
    GpioCtrlRegs.GPCDIR.bit.GPIO64=1; //
    GpioCtrlRegs.GPCDIR.bit.GPIO65=1; //
    GpioCtrlRegs.GPCDIR.bit.GPIO66=1; //
    GpioCtrlRegs.GPCDIR.bit.GPIO67=1; //
    GpioCtrlRegs.GPCDIR.bit.GPIO68=1; //
    EDIS;
    // 低电平开启所有
    GpioDataRegs.GPACLEAR.bit.GPIO10=1;
    GpioDataRegs.GPACLEAR.bit.GPIO11=1;
    GpioDataRegs.GPCCLEAR.bit.GPIO64=1;
    GpioDataRegs.GPCCLEAR.bit.GPIO65=1;
    GpioDataRegs.GPCCLEAR.bit.GPIO66=1;
    GpioDataRegs.GPCCLEAR.bit.GPIO67=1;
    GpioDataRegs.GPCCLEAR.bit.GPIO68=1;

}
void ConfigRelay(void){

    EALLOW;
    GpioCtrlRegs.GPADIR.bit.GPIO15=1;  // 设置为输出方向
    EDIS;
    GpioDataRegs.GPACLEAR.bit.GPIO15=1;
}
void ConfigMotor(void){
     EALLOW;
     GpioCtrlRegs.GPADIR.bit.GPIO2=1;  // 设置为输出方向
     GpioCtrlRegs.GPADIR.bit.GPIO3=1;  // 设置为输出方向
     EDIS;
     GpioDataRegs.GPACLEAR.bit.GPIO3=1;
     GpioDataRegs.GPASET.bit.GPIO3=1;

}
void ConfigBeep(void){
       EALLOW;
       GpioCtrlRegs.GPADIR.bit.GPIO6=1;  // 设置为输出方向
       EDIS;

}
/**
             调整占空比,改变音调
              GpioDataRegs.GPASET.bit.GPIO6=1;
             DELAY_US(10000);
             GpioDataRegs.GPATOGGLE.bit.GPIO6=1;
             DELAY_US(10000);
 */

void ConfigKeys(void){
          EALLOW;
          GpioCtrlRegs.GPADIR.bit.GPIO12=0;  // 设置为输入方向
          GpioCtrlRegs.GPADIR.bit.GPIO13=0;  // 设置为输入方向
          GpioCtrlRegs.GPADIR.bit.GPIO14=0;  // 设置为输入方向
          GpioCtrlRegs.GPAQSEL1.bit.GPIO0=1; //设置量化周期为3个
          GpioCtrlRegs.GPACTRL.bit.QUALPRD0=0xFF; // 6.66usx2x225

          GpioCtrlRegs.GPBDIR.bit.GPIO48=1;
          GpioCtrlRegs.GPBDIR.bit.GPIO49=1;
          GpioCtrlRegs.GPBDIR.bit.GPIO50=1;

          EDIS;
          GpioDataRegs.GPBCLEAR.bit.GPIO48=1;
          GpioDataRegs.GPBCLEAR.bit.GPIO49=1;
          GpioDataRegs.GPBCLEAR.bit.GPIO50=1;

          /***
            if(!GpioDataRegs.GPADAT.bit.GPIO12){
          GpioDataRegs.GPCTOGGLE.bit.GPIO66=1;
            }
         if(!GpioDataRegs.GPADAT.bit.GPIO13){
          GpioDataRegs.GPCTOGGLE.bit.GPIO67=1;
            }
         if(!GpioDataRegs.GPADAT.bit.GPIO14){
           GpioDataRegs.GPCTOGGLE.bit.GPIO68=1;
          }
           */


}





