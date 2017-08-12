// FixModelDlg.cpp : implementation file
//

#include "stdafx.h"
#include "HsbVision.h"
#include "FixModelDlg.h"
#include "afxdialogex.h"
#include "afxpropertygridctrl.h"

// CFixModelDlg dialog

IMPLEMENT_DYNAMIC(CFixModelDlg, CDialogEx)

CFixModelDlg::CFixModelDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFixModelDlg::IDD, pParent)
{
// 	m_pShape = new CShapeMatch();
}

CFixModelDlg::~CFixModelDlg()
{
// 	if (NULL !=m_pShape)
// 	{
// 		delete m_pShape;
// 		m_pShape = NULL;
// 	}
}

void CFixModelDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
// 	DDX_Control(pDX, IDC_SLIDER_CONSTRAT, m_SliderContrast);
	DDX_Control(pDX, IDC_MFCPROPERTYGRID1, m_proPertyCtrl);
}


BEGIN_MESSAGE_MAP(CFixModelDlg, CDialogEx)
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_BUTTON_SAVE_OPRATION, &CFixModelDlg::OnBnClickedButtonSaveOpration)
END_MESSAGE_MAP()

BOOL  CFixModelDlg::OnInitDialog()
{

// 	int nn =pHvisio->add();

	CDialogEx::OnInitDialog();

	MoveWindow(g_nCXScreen - 220,g_nCYTitle + g_nCYMenu + g_nCYToolBar+5, 220,g_nCYClient);
// 	m_SliderContrast.SetRange(0,125);
// 	m_SliderContrast.SetPos(15);
// 	SetDlgItemInt(IDC_STATIC_CONSTRAT,m_SliderContrast.GetPos());
// 	SetDlgItemText(IDC_EDIT_MIN_SCORE, _T("0.4"));
// 	SetDlgItemText(IDC_EDIT_PASS_VAL,  _T("0.88") );


	HDITEM item;
	item.cxy=80;
	
	item.mask=HDI_WIDTH;   

	m_proPertyCtrl.GetHeaderCtrl().SetItem(0, new HDITEM(item)); 
	m_proPertyCtrl.GetHeaderCtrl().SetItem(2, new HDITEM(item)); 

	CMFCPropertyGridProperty* pGroup1 = new CMFCPropertyGridProperty(_T("����"));
	pGroup1->AddSubItem(new CMFCPropertyGridProperty(_T("����"), (_variant_t)_T("����1"), _T("��������ͼ����ʾ�ı�������")));
	pGroup1->AddSubItem(new CMFCPropertyGridProperty(_T("����"), (_variant_t)_T("����1"), _T("��ǰ��ʾ�ƻ��ļ���")));
	m_proPertyCtrl.AddProperty(pGroup1);


// 	CMFCPropertyGridProperty  *pProp1 = new CMFCPropertyGridProperty(  _T("�쳯�ʺ�������"),_T("51CTO��̸����"),_T("������������"));
// 
// 	m_proPertyCtrl.AddProperty(pProp1);


	CMFCPropertyGridProperty* pProp2 = new CMFCPropertyGridProperty(  
		_T("���ǲ���˧�磿"),    
		_T("��ѡ��"),   
		_T(""));   

	pProp2->AddOption(_T("��"));   
	pProp2->AddOption(_T("�϶���"));   
	pProp2->AddOption(_T("������"));   
	pProp2->AllowEdit(FALSE);  //�������ѡ����б༭  
	m_proPertyCtrl.AddProperty(pProp2);
	

	CMFCPropertyGridColorProperty * pProp3 = new CMFCPropertyGridColorProperty( 
		_T("��ɫ"), RGB(0, 111, 200)); 
	m_proPertyCtrl.AddProperty(pProp3); 

	CMFCPropertyGridFileProperty * pProp4 = new CMFCPropertyGridFileProperty(
		_T("���ļ�"), TRUE, _T("D:\\test.txt")); 
	m_proPertyCtrl.AddProperty(pProp4); 

	LOGFONT font = {NULL}; 
	CMFCPropertyGridFontProperty * pProp5 = new CMFCPropertyGridFontProperty(_T("ѡ������"), font); 
	m_proPertyCtrl.AddProperty(pProp5); 

	int nn = m_proPertyCtrl.GetHeaderHeight();
	int n1 = m_proPertyCtrl.GetRowHeight();
// 	CMFCPropertyGridSliderProperty *pProp6 = new CMFCPropertyGridSliderProperty(_T("ѡ��slider"), font);

// 	CMFCPropertyGridProperty * group1 = new CMFCPropertyGridProperty(_T("����1")); 
// 	CMFCPropertyGridProperty * group2 = new CMFCPropertyGridProperty(_T("����2")); 

// 	group1->AddSubItem(pProp2); 
// 	group2->AddSubItem(pProp3); 
// 	group2->AddSubItem(pProp4); 
// 	group2->AddSubItem(pProp5); 

// 	m_proPertyCtrl.AddProperty(group1); 
// 	m_proPertyCtrl.AddProperty(group2); 


	return TRUE;
}


// CFixModelDlg message handlers
void CFixModelDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: Add your message handler code here and/or call default
	switch(pScrollBar->GetDlgCtrlID())
	{
	case IDC_SLIDER_CONSTRAT:
// 		m_pShape->OnSetMincontrast(m_SliderContrast.GetPos());
		SetDlgItemInt(IDC_STATIC_CONSTRAT,m_SliderContrast.GetPos());
		break;
	}
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}

#include "WorkingProcDlg.h"
void CFixModelDlg::OnBnClickedButtonSaveOpration()
{
	// TODO: Add your control notification handler code here
	CWorkingProcDlg dlg;
	dlg.DoModal();
}

