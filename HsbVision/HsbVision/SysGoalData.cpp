#include "stdafx.h"
#include "SysGoalData.h"

//------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------
UINT  g_nCXScreen = 0;//��Ļ���
UINT  g_nCYScreen = 0;//��Ļ�߶�
UINT  g_nCYTitle;//�������߶�
UINT  g_nCYMenu =22;//�˵����߶�
UINT  g_nCYToolBar = 56;//�������߶�
UINT  g_nCYClient;//�ͻ����߶�
CFont  *g_cFont[4];
vector<LIGHT_INFO> g_LightInfo;
vector<HTEXTTOOLELEM> g_hTextTool;
CDialog  *m_pCaptureDlg;

// Bo_Halcon g_boHalcon;
//------------------------------------------------------------------------------------------------------------

int		g_nMaxEQ			= 28;			//EQ���ֵ
int		g_nMaxBALANCE		= 40;			//����ƽ�ⷶΧ
int		g_nMaxLOUNDNESS		= 19  ;			//ǰ������ƽ�ⷶΧ


DWORD	g_dwDvdEndTime		= 0;			//����˳�DVDԴ��ʱ��
BOOL	g_bInEjectIng		= FALSE	;		//�Ƿ����ڳ�����


UINT32	g_nEQType			= 0;
int		g_ntreble			= 0;			//����
int		g_nbass				= 0;			//����
int		g_nloudness			= 0;			//���
POINT	g_ptBalance			= { 0,0 };		//��ǰ���õ���Чƽ���



BOOL		g_bNavVol		  = FALSE	; //�����Ƿ����ڷ���
BOOL		g_bNavShow		  = FALSE	; //���������Ƿ���ǰ̨��ʾ


UINT16		g_nCameraMirror	  = MIR_NONE;	//��������״̬
DWORD		g_dwLangLCID	  = 0X0409;		//��ǰ���Ե�LCID


//------------------------------------------------------------------------------------------------------------
int					g_nSkinIndex = SKIN_1;

BOOL				g_bNoDvd	= FALSE;
BOOL				g_bNoMcuTV	= FALSE;
BOOL				g_bNoAux1	= FALSE;
BOOL				g_bNoAux2	= FALSE;
BOOL				g_bNoCMMB	= TRUE;
BOOL				g_bNoATV	= TRUE;


BOOL				g_bSerialIpod =  FALSE;


//------------------------------------------------------------------------------------------------------------
//SRC_CMMB,
//SRC_NAVIGATION
// BYTE	g_SrcOrder[0x20]		= {  SRC_RADIO,SRC_DISC,SRC_USB,SRC_USB_REAR,SRC_SD,SRC_BT,
// 										SRC_AUX_1,SRC_AUX_2,SRC_MCUTV,SRC_CMMB,SRC_IPOD ,0,0};

BYTE	g_bytModeCount				= 0x0;

//------------------------------------------------------------------------------------------------------------


BYTE		g_bytSSType		= SCN_TY_0;
DWORD		g_dwLastMouseT	= 0;
BOOL		g_bForbidScreenSave = FALSE;


//------------------------------------------------------------------------------------------------------------
// BYTE	g_bakSrcBefRds = SRC_OFF;
