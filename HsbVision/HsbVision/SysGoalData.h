#pragma once
// #include "Bo_Halcon.h"

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------

typedef struct tagHTEXTTOOLELEM
{
	CHAR  tool_name[MAX_PATH];
	vector<string > tool_item;
} HTEXTTOOLELEM;

struct  LIGHT_INFO{
	WORD  ncom;
	WORD  nbaud;
	WORD  val1;
	WORD  val2;
	WORD  val3;
	WORD  val4;
	LIGHT_INFO()
	{
		ncom = 1;
		nbaud = 19200;
		val1 = val2 = val3 = val4 =0;
	}
};

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
extern UINT  g_nCXScreen;//��Ļ���
extern UINT  g_nCYScreen;//��Ļ�߶�
extern UINT  g_nCYTitle;//�������߶�
extern UINT  g_nCYMenu;//�˵����߶�
extern UINT  g_nCYToolBar;//�������߶�
extern UINT  g_nCYClient;//�ͻ����߶�

/*extern UINT  g_nCYClient;//�ͻ����߶�*/
extern CFont  *g_cFont[4];

extern   vector<LIGHT_INFO> g_LightInfo;
extern   vector<HTEXTTOOLELEM> g_hTextTool;
extern   CDialog  *m_pCaptureDlg;

// extern Bo_Halcon g_boHalcon;

//-----------------------------------------------------------------------------------------------------------------

extern int		g_nMaxEQ;
extern int		g_nMaxBALANCE  ;	//ǰ������ƽ�ⷶΧ
extern int		g_nMaxLOUNDNESS  ;	//ǰ������ƽ�ⷶΧ

extern UINT16	g_nCameraMirror;	//��������״̬
extern DWORD	g_dwLangLCID;		//��ǰ���Ե�LCID

//-----------------------------------------------------------------------------------------------------------------
//------------------------------------------ �����汳��   ----------------------------------------------------------

enum	SKIN_TYPE { SKIN_0, SKIN_1,SKIN_2,SKIN_3,SKIN_4,SKIN_5,SKIN_6,SKIN_7,SKIN_8,SKIN_9,SKIN_ALL };
extern  int   g_nSkinIndex;

//------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------
//��������
enum  MIRROR_TYPE { MIR_NONE,MIR_HOR,MIR_VER,MIR_H_V,MIR_ALL };


extern  UINT32		g_nEQType;			//��ǰѡ�����Ч����
extern  POINT		g_ptBalance;		//��ǰ���õ���Чƽ���

extern  int			g_ntreble;			//����
extern  int			g_nbass;			//����
extern  int			g_nloudness;		//���
 
extern	BOOL		g_bNavVol;			//�����Ƿ����ڷ���
extern  BOOL		g_bNavShow;			//���������Ƿ���ǰ̨��ʾ

extern  BOOL		g_bInEjectIng;		//��������������ڳ���״̬

//����˳�DVDԴ��ʱ��
extern DWORD		g_dwDvdEndTime;


//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
//Ŀǰ״̬��Ĭ������Դ����Ϊ���ڣ�ֻ�������ļ��ﶨ���˲�����ʱ��APP����Ϊ������
extern  BOOL		g_bNoDvd;
extern  BOOL		g_bNoMcuTV;
extern  BOOL		g_bNoAux1;
extern  BOOL		g_bNoAux2;
extern  BOOL		g_bNoCMMB;
extern  BOOL		g_bNoATV;


extern  BOOL		g_bSerialIpod;

//-----------------------------------------------------------------------------------------------------------------
#define COUNT_M_SRC			0x0B
extern  BYTE		g_SrcOrder[0x20];

extern	BYTE		g_bytModeCount;

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------

enum SCREEN_SAVE_TYPE { SCN_TY_0,SCN_TY_15S,SCN_TY_30S,SCN_TY_1M,SCN_TY_3M,SCN_TY_5M,SCN_TY_ALL };
extern	BYTE		g_bytSSType;
extern	DWORD		g_dwLastMouseT;
extern  BOOL		g_bForbidScreenSave;

//---------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------
extern	BYTE	g_bakSrcBefRds;
