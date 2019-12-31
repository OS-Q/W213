
#include "stm8l15x.h"
//����LED�밴���ӿ�
#define LED_GPIO_PORT  GPIOA
#define LED_GPIO_PINS  GPIO_Pin_6
#define KEY_GPIO_PORT  GPIOB
#define KEY_GPIO_PINS  GPIO_Pin_4
/*******************************************************************************
****��ڲ�������
****���ڲ�������
****������ע������PB5�ĵ�ѹֵ��֤DAC�Ľ��
****��Ȩ��Ϣ��OS-Q
*******************************************************************************/
int main( void )
{
  CLK_PeripheralClockConfig(CLK_Peripheral_DAC, ENABLE);//������DACʱ��
  CLK_PeripheralClockConfig(CLK_Peripheral_COMP, ENABLE);//������Ƚ���ʱ�ӣ������
     //   RI->IOSR2    =0x10;
     //   RI->IOCMR2   =0x10;
  
  SYSCFG_RIIOSwitchConfig(RI_IOSwitch_14,ENABLE);//CH13E--PB6,CH14E--PB5 ,CH15E--PB4    
        
  DAC_DeInit();//Ĭ��ֵ
  
  DAC_Init(DAC_Channel_1, DAC_Trigger_None, DAC_OutputBuffer_Disable);//DAC���ͨ��1��PB5
  DAC_Cmd(DAC_Channel_1, ENABLE);//ʹ��ͨ��1
  DAC_SetChannel1Data(DAC_Align_12b_R,2048);//12λ�Ҷ��룬�ı���������ֵ����ͨ������PB5�ĵ�ѹ��֤DAC���
   
  while(1)
  {
    
  }
}
