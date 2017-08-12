// ToolsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "HsbVision.h"
#include "ToolsDlg.h"
#include "LightControlDlg.h"
#include "HsbVisionDlg.h"
#include "FixModelDlg.h"
#include "CaptureImageDlg.h"
#include "PropertyDlg.h"
// CToolsDlg dialog

IMPLEMENT_DYNAMIC(CToolsDlg, CDialogEx)

CToolsDlg::CToolsDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CToolsDlg::IDD, pParent)
{
	m_pPropertyDlg = NULL;
}

CToolsDlg::~CToolsDlg()
{
}

void CToolsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE1, m_TreeList);
}


BEGIN_MESSAGE_MAP(CToolsDlg, CDialogEx)
	ON_WM_TIMER()
	ON_NOTIFY(NM_DBLCLK, IDC_TREE1, &CToolsDlg::OnNMDblclkTree1)
	ON_NOTIFY(NM_CLICK, IDC_TREE1, &CToolsDlg::OnNMClickTree1)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE1, &CToolsDlg::OnTvnSelchangedTree1)
END_MESSAGE_MAP()


// CToolsDlg message handlers
BOOL CToolsDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetWindowText(_T("������"));

	// TODO:  Add extra initialization here
	int cx = GetSystemMetrics(SM_CXFULLSCREEN);
	int cy = GetSystemMetrics(SM_CYFULLSCREEN);

	int   cx1   =   GetSystemMetrics(   SM_CXSCREEN   );
	int   cy2   =   GetSystemMetrics(   SM_CYSCREEN   );
	MoveWindow(0, g_nCYTitle + g_nCYMenu + g_nCYToolBar+5,199,g_nCYClient -30);
	CRect rect ;
	GetClientRect(&rect);
	
	m_TreeList.MoveWindow(&rect);

	m_TreeList.ModifyStyle(NULL, WS_VISIBLE | WS_TABSTOP | WS_CHILD | WS_BORDER | TVS_HASBUTTONS | TVS_LINESATROOT | TVS_HASLINES| TVS_DISABLEDRAGDROP,0);
	CFont font;
	font.CreateFont(19,10,0,0,FW_THIN,false,false,false,
		CHINESEBIG5_CHARSET,OUT_CHARACTER_PRECIS,
		CLIP_CHARACTER_PRECIS,DEFAULT_QUALITY,
		FF_MODERN, _T("΢���ź�"));


	m_TreeList.SetLineColor(RGB(255,0,0));
// 	m_TreeList.SetTextColor(RGB(128,138,220));
	m_TreeList.SetTextColor(RGB(33,53,53));

// 	m_TreeList.SetFont(&font);
	HICON icon[4];
	icon[0]=AfxGetApp()->LoadIcon(IDI_ICON_TOOLS);
	icon[1]=AfxGetApp()->LoadIcon(IDI_ICON_SETTING);


	CImageList *ImageList4Tree = new CImageList;
	ImageList4Tree->Create(30,30,ILC_COLOR32 | ILC_MASK,4,4); //16,16Ϊͼ��ֱ��ʣ�4,4Ϊ��list��������ɵ�ͼ����
// 	ImageList4Tree->SetBkColor(RGB(255,255,0));
	for(int i=0;i<2;i++)
	{
		ImageList4Tree->Add(icon[i]); //����ͼ��
	}
	m_TreeList.SetImageList(ImageList4Tree,TVSIL_NORMAL);

	m_TreeList.SetBkColor(RGB(180,250,255));//����m_mytree�ı���ɫ
	DWORD dwMinSize;
// 	dwMinSize = WideCharToMultiByte(CP_OEMCP,NULL,wbuf2[0],-1,NULL,0,NULL,FALSE);
	char buf[255] = {0};
	char *buf1 = "���";
// 	WideCharToMultiByte(CP_OEMCP,NULL,wbuf2[0],-1,buf,255,NULL,FALSE);

	int nsize = g_hTextTool.size();
	for (int i = 0; i < nsize; i++)
	{
		HTREEITEM hRoot0 = m_TreeList.InsertItem(g_hTextTool[i].tool_name, 0,0);//��2��������item����Ӻú��ͼ��   //��3������Ϊitem�ڱ�ѡ�к��ͼ��
		m_TreeList.SetItemState(hRoot0, TVIS_BOLD, TVIS_BOLD);
		int nItem = g_hTextTool[i].tool_item.size();
		for (int j= 0;j<nItem; j++)
		{
			m_TreeList.SetItemState(m_TreeList.InsertItem(g_hTextTool[i].tool_item[j].c_str(), 1, 1, hRoot0), TVIS_BOLD, TVIS_BOLD);
		}
	}

// 	m_ImagePreProcessing = new CImagePreProcessing();
	SetTimer(1,5,NULL);
	return TRUE;

	// 	m_TreeList.InsertItem(_T("��ɫת��"), 0, 1, hSrc);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void CToolsDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	if (1 == nIDEvent)
	{
		KillTimer(1);
		m_TreeList.SelectItem(NULL);
		SetWindowText(_T("������"));

	}
	CDialogEx::OnTimer(nIDEvent);
}

void CToolsDlg::OnTvnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
	HTREEITEM m_hTreeItem = m_TreeList.GetSelectedItem();
	CString S1 = m_TreeList.GetItemText(m_hTreeItem);
	if (S1.GetLength()>0)
	{
		CString strText = CString(_T("������-"))+S1;
		SetWindowText(strText);
	}
}

void CToolsDlg::OnNMClickTree1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	*pResult = 0;

}

void CToolsDlg::OnNMDblclkTree1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	*pResult = 0;
	HTREEITEM m_hTreeItem = m_TreeList.GetSelectedItem();
	CString S1 = m_TreeList.GetItemText(m_hTreeItem);
	int nCount = m_TreeList.GetCount();
	HTREEITEM  hTreeItem =   m_TreeList.GetSelectedItem();
// 	m_TreeList.GetItem();

	OnDoItemEvent(S1);

// 	CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);  
// 	CHsbVisionView* pView = (CHsbVisionView*)pFrame->GetActiveView();
// 	pView->OnDoItemEvent(S1);
}

void CToolsDlg::OnDoItemEvent(LPCTSTR  pItemText)
{
	if (CString(_T("��Դ����")) == CString(pItemText))
	{
		CLightControlDlg  LightCtlDlg;
		LightCtlDlg.DoModal();
		int i =0;
	}

	else if ( CString(_T("��ͼ��")) == CString(pItemText)  )
	{
		CString strFilePath;
		CFileDialog dlg( TRUE,(_T(".png;.bmp;.jpg;.jpeg;.TIF")),(_T("*.png;*.bmp;*.jpg;*.jpeg;*.TIF")),OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, 0, this);
		if (dlg.DoModal() == IDOK) strFilePath = dlg.GetPathName();
		else return;

		DWORD dwMinSize;
		char lpszStr[255];
// 		dwMinSize = WideCharToMultiByte(CP_OEMCP,NULL,strFilePath,-1,NULL,0,NULL,FALSE);
// 		WideCharToMultiByte(CP_OEMCP,NULL,strFilePath,-1,lpszStr,dwMinSize,NULL,FALSE);
// 		g_boHalcon.OnLoadImage(strFilePath.GetBuffer());
// 		g_boHalcon.OnShowImage();
	}

	else if (CString(_T("��ɫת��")) == CString(pItemText) )
	{
// 		m_ImagePreProcessing->RGB2SingleChannel(0);
		OnShowPropertyDlg(pItemText);

	}

	else if ( CString(_T("ͼ��λ")) == CString(pItemText) )
	{
		OnShowPropertyDlg(pItemText);
	}

	else if (CString("�ߵ����") == CString(pItemText))
	{
		OnShowPropertyDlg(pItemText);
	}
	else if (CString("�ַ����") == CString(pItemText))
	{
		CFixModelDlg  dlg;
		dlg.DoModal();
	}

	else if ( CString(_T("ͼ��ɼ�")) == CString(pItemText) )
	{
// 		CHsbVisionDlg::GetDlgInstance()->OnF2();
		CHsbVisionDlg::GetDlgInstance()->OnCreateDialog(IDD_DIALOG_CAPUTRUE,this);

// 		CDialog *m_pCaptureDlg = NULL;
// 		if (NULL == m_pCaptureDlg)
// 		{
// 			m_pCaptureDlg = new CcaptureImageDlg;
// 			if ( m_pCaptureDlg)
// 			{
// 				BOOL ret = m_pCaptureDlg->Create(IDD_DIALOG_CAPUTRUE,this);
// 				m_pCaptureDlg->ShowWindow(SW_SHOW);
// 			}
// 		}
	}
}

void CToolsDlg::OnShowPropertyDlg(LPCTSTR  pItemText, BOOL bShow)
{

	if (NULL == m_pPropertyDlg)
	{
		m_pPropertyDlg = new CPropertyDlg(pItemText);
// 		m_pPropertyDlg->SetToolAttr(pItemText);
		m_pPropertyDlg->Create(IDD_DIALOG_PROPERTY,this);
	}

	if (NULL != m_pPropertyDlg)
	{
		m_pPropertyDlg->SetToolAttr(pItemText);
		m_pPropertyDlg->ShowWindow(SW_SHOW);
	}

}
