#ifndef __MAIN_H
#define __MAIN_H
#ifdef __cplusplus
 extern "C" {
#endif
#include "stm32f4xx.h"
#include "stm32f4x7_eth_bsp.h"
#include "serial_hand.h"
//#define Sync_Device 			//ʱ��ͬ���豸
//#define Device_Slave 			//���豸
extern	 uint8_t PTP_MS_MODE ;
//���ܿ���
#define NTP_Server
#define PTP_Device	 

//#define Gx_PTP_Device						//ptp������ģ��
//godin ����ģ�鿪�ض���	 
//#define NTP_Philips	 
//#define NTP_Client	
//#define FreqMassage

	 
#define mLED1 GPIO_Pin_11
#define mLED2 GPIO_Pin_12
#define mLED3 GPIO_Pin_13
#define mLED4 GPIO_Pin_14

#define Default_System_Time    1388592000
#define myprintf  printf

typedef struct FigStruct//CAN������Ϣ�ṹ
{             
	uint32_t IPaddr;  		//����IP
	uint32_t NETmark;			//������������

	uint32_t GWaddr;			//��������
	uint32_t DstIpaddr;		//�Զ�IP

	uint16_t LocalPort;		//���ض˿�
	uint16_t DstPort;			//Ŀ�Ķ˿�
	uint8_t  WorkMode;		//ptp����ģʽ
	uint8_t  clockClass;
	uint8_t	 UTCoffset;		
  uint8_t  ip_mode;			//NTP����ģʽ(�����鲥�㲥)	


	uint8_t  MACaddr[6];	//����MAC��ַ
	uint8_t  MSorStep;		//һ����������	
	uint8_t  ClockDomain;	//ʱ����
	

	char  AnnounceInterval;	
	uint8_t AnnounceOutTime;	 
	char  SyncInterval;			
	uint8_t PDelayInterval;		
	uint8_t DelayInterval;
	uint8_t priority1;
	uint8_t priority2;
	uint8_t	tmp2;
}FigStructData;


void Time_Update(void);
void Delay(uint32_t nCount);
void STM_LEDon(uint16_t LEDx);
void STM_LEDoff(uint16_t LEDx);


#ifdef __cplusplus
}
#endif

#endif
