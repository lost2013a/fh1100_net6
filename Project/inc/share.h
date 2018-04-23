#ifndef __SHARE_H
#define __SHARE_H

#include "ntp.h"
#include "main.h"
#include "flash_conf.h"

#ifdef __cplusplus
 extern "C" {
#endif

#define NTPSET_PORT 7861
	 
//#if defined(Sync_Device)
struct Sync_UartData
{
	unsigned char frame_head;
	unsigned char state_flag1;
	unsigned char state_flag2;
	unsigned char state_flag3;
	unsigned char state_flag4;
	unsigned char year_4;
	unsigned char year_3;
	unsigned char year_2;
	unsigned char year_1;
	unsigned char month_2;
	unsigned char month_1;
	unsigned char day_2;
	unsigned char day_1;
	unsigned char hour_2;
	unsigned char hour_1;
	unsigned char min_2;
	unsigned char min_1;
	unsigned char sec_2;
	unsigned char sec_1;
	unsigned char chksum_2;
	unsigned char chksum_1;
	unsigned char end_flag1;
	unsigned char end_flag2;
};
//#endif

typedef struct {   //godin ���ڷ�����Ϣ�ṹ
  unsigned char synA;				 //ͬ����  90
  unsigned char synB;				 //ͬ����  eb
//  unsigned char command;				 //������
//  unsigned char addencode;			 //�忨��ַ
  unsigned char messagelen;			 //���ĳ���	0x1a
  unsigned char year1;		
  unsigned char year2;		
  unsigned char	 month;
  unsigned char	 day;
  unsigned char  hour;
  unsigned char  minute;
  unsigned char  seconds;//10
  char leap;				 		 //������	 0������1�����룬2�����룬3δ֪
  char sync_state;			 //ͬ��״̬	 A��Ч41H  V��Ч56H  //12
  char onetwostep;				 //����ģʽ //һ����������������Ч
	char sync_mode; 			 //ͬ��ģʽ
  char Running_state;		 //ptp����״̬
  char bestmac_addr[6];		//15-20
  //char mac_addr[6];		
  char  path_delay[4];				
  char  correctionField[4];		
  char chksum;				 //У���	//30
}ARMtoFH1100;
#ifdef Oscil_Device
struct Send_TimeMessage
{
	unsigned char	syn_ch1_8;				// ͬ���ַ� 						1 (90H)
	unsigned char	syn_ch2_8;				// ͬ���ַ�							1	(EBH)
	unsigned char send_timef_8;			// ����ʱ����					1 (11H)
	unsigned char	addr_8;						// ��ַ�� 	   					1 (51H)
	unsigned char	len_8;						// ���ĳ�								1	(09H)
	unsigned char HYear;						// ���2λ							1
	unsigned char LYear;						// ���2λ							1	
	unsigned char Mon;							// �·�λ								1
	unsigned char Day;							// ����λ								1	
	unsigned char Hour;							// Сʱλ								1	
	unsigned char Min;							// ����λ								1	
	unsigned char Sec;							// ��λ								  1	
	unsigned char leap_flag;				// ������							1	(0����,1������,2������,3δ֪)
	unsigned char adj_flags;				// ʱ���Ѿ�У׼���			1 (A��Ч41H,V��Ч56H)
	unsigned char chkSum_8;					// �����								1	
};
#endif



#define MSG_ONESTEP  0
#define MSG_TWOSTEP  1

#define MSG_P2PMODE 0
#define MSG_E2EMODE 1

#define MSG_UDPMODE 0
#define MSG_ETHMODE 1

#define MSG_MASTERCLOCK  0
#define MSG_SLAVECLOCK   1


#define COMDEF_GETSETINFO      1
#define COMDEF_ACKGETSETINFO   2
#define COMDEF_SETINFO         3
#define COMDEF_ACKSETINFO      4 
#define COMDEF_GETDISPLAY      5 
#define  COMDEF_ACKDISPLAY     6
#define COMDEF_SENDIP					 7
#define COMDEF_IP							 8

typedef struct SendIP
{
	unsigned int  net_ip;
	unsigned int  net_gw;
	unsigned int  net_mark;
}__attribute__((packed)) Send_IP;


typedef struct SetIP
{
	unsigned int  ip;
	unsigned short port;
	unsigned char time;
}__attribute__((packed)) Set_IP;

typedef struct tagUdpcom
{
   unsigned char comtype;
   unsigned char data[50];

}__attribute__((packed)) UDP_COM;

/*����ṹ�嶨��*/
typedef struct TAGPTPSETMSG //godin �������ýṹ��
{
	unsigned int  ip;	
	unsigned int  gw_ip;
	unsigned int  SubnetMask;
	unsigned char ETHERNET_MODE;
	unsigned char MULTICAST_MODE;
	unsigned char E2E_mode;
	unsigned char ANNOUNCE_INTERVAL;
	unsigned char ANNOUNCE_RECEIPT_TIMEOUT;
	unsigned char SYNC_INTERVAL;
	unsigned char PDELAYREQ_INTERVAL;
  unsigned char DELAYREQ_INTERVAL;
	unsigned char SLAVE_PRIORITY1 ;//���ȼ�1
  unsigned char SLAVE_PRIORITY2 ;//���ȼ�2
  unsigned char DOMAINNUMBER ;//ʱ����
  unsigned char TWOSTEPFLAG ;//������
	
}__attribute__((packed)) PTP_SETMSG;

typedef struct  TAGPTPDISPLAY
{
  unsigned char    clock_type;
	unsigned char    twostepflag;
	unsigned char    ethernet_mode;
	unsigned char    e2e_mode;
	unsigned char    portState;
	unsigned char    timeSource;
  unsigned char    bestmasterclock_mac[6];	
	char     				 local_mac[6];
	unsigned char    warning_signal;
	int                 offsetFromMaster_seconds;
	int                 offsetFromMaster_nanoseconds;
	int                meanPathDelay_seconds;
	int                meanPathDelay_nanoseconds;
}__attribute__((packed))  PTP_DISPLAY;//ʵ��ռ���ֽ�ģʽ(ȡ���Զ�����)

typedef struct
{
	unsigned short usYear;//! The number of years since 0 AD.
	unsigned char ucMon; //! The month, where January is 0 and December is 11.
	unsigned char ucMday; //! The day of the month.
	unsigned char ucWday;//! The day of the week, where Sunday is 0 and Saturday is 6.
	unsigned char ucHour; //! The number of hours.
	unsigned char ucMin; //! The number of minutes.
	unsigned char ucSec; //! The number of seconds.
}
tTime;


//*****************************************************************************
// This array contains the number of days in a year at the beginning of each
// month of the year, in a non-leap year.
//*****************************************************************************
static const short g_psDaysToMonth[12] =
{
    0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334
};
static const char *ppcDay[7] =
{
    "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"
};
static const char *ppcMonth[12] =
{
    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
};


void Send_FreqMassage(void);
void ulocaltime(unsigned long ulTime, tTime *psTime);
void NTP_Init(void);

void NTPClientLoop(void);
void offset_time(sysTime *calcTime);
void abjClock(const TimeInternal subtime);
long prmtread_decimal(unsigned char *p,unsigned char n);
unsigned long  Serial_Htime(tTime *sulocaltime);
unsigned long TimeToSeconds( tTime *psTime );
unsigned char getCfgDataHeadSum(unsigned char* ptr,int len);
unsigned char char_to_8421(const unsigned char num);
void Debug_Time(tTime Time,Integer32 nanoseconds);
void UARTSend(const unsigned char *pucBuffer, unsigned long ulCount);

#ifdef __cplusplus
}
#endif
#endif