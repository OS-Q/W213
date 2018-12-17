
#include "stm8l15x.h"
//定义LED与按键接口
#define LED_GPIO_PORT  GPIOA
#define LED_GPIO_PINS  GPIO_Pin_6
#define KEY_GPIO_PORT  GPIOB
#define KEY_GPIO_PINS  GPIO_Pin_4
/*******************************************************************************
****入口参数：无
****出口参数：无
****函数备注：测量PB5的电压值验证DAC的结果
****版权信息：OS-Q
*******************************************************************************/
int main( void )
{
  CLK_PeripheralClockConfig(CLK_Peripheral_DAC, ENABLE);//打开外设DAC时钟
  CLK_PeripheralClockConfig(CLK_Peripheral_COMP, ENABLE);//打开外设比较器时钟，必须打开
     //   RI->IOSR2    =0x10;
     //   RI->IOCMR2   =0x10;
  
  SYSCFG_RIIOSwitchConfig(RI_IOSwitch_14,ENABLE);//CH13E--PB6,CH14E--PB5 ,CH15E--PB4    
        
  DAC_DeInit();//默认值
  
  DAC_Init(DAC_Channel_1, DAC_Trigger_None, DAC_OutputBuffer_Disable);//DAC输出通道1，PB5
  DAC_Cmd(DAC_Channel_1, ENABLE);//使能通道1
  DAC_SetChannel1Data(DAC_Align_12b_R,2048);//12位右对齐，改变后面参数的值可以通过测量PB5的电压验证DAC结果
   
  while(1)
  {
    
  }
}

