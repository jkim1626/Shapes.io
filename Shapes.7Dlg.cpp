
// Shapes.7Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Shapes.7.h"
#include "Shapes.7Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CShapes7Dlg dialog



CShapes7Dlg::CShapes7Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SHAPES7_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CShapes7Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CShapes7Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDCANCEL, &CShapes7Dlg::OnBnClickedCancel)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CShapes7Dlg::OnCbnSelchangeCombo1)
	ON_EN_CHANGE(IDC_EDIT1, &CShapes7Dlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &CShapes7Dlg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT3, &CShapes7Dlg::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT4, &CShapes7Dlg::OnEnChangeEdit4)
	ON_EN_CHANGE(IDC_EDIT5, &CShapes7Dlg::OnEnChangeEdit5)
	ON_EN_CHANGE(IDC_EDIT6, &CShapes7Dlg::OnEnChangeEdit6)
	ON_EN_CHANGE(IDC_EDIT7, &CShapes7Dlg::OnEnChangeEdit7)
END_MESSAGE_MAP()


// CShapes7Dlg message handlers

BOOL CShapes7Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}


	// Picture Control Set up
	CStatic* pPicture = reinterpret_cast<CStatic*>(GetDlgItem(IDC_STATIC));
	pPicture->ModifyStyle(0xF, SS_BITMAP, SWP_NOSIZE);
	HBITMAP hb = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDB_BITMAP1), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
	pPicture->SetBitmap(hb);

	CComboBox* pCombo = reinterpret_cast<CComboBox*>(GetDlgItem(IDC_COMBO1));
	pCombo->InsertString(0, _T("Square"));
	pCombo->InsertString(1, _T("Cube"));
	pCombo->InsertString(2, _T("Rectangle"));
	pCombo->InsertString(3, _T("Box"));
	pCombo->InsertString(4, _T("Circle"));
	pCombo->InsertString(5, _T("Cylinder"));
	pCombo->InsertString(6, _T("Triangle"));
	pCombo->InsertString(7, _T("Prism"));
	pCombo->InsertString(8, _T("--Select--"));
	pCombo->SetCurSel(8); // or -1 for unselected


	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CShapes7Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CShapes7Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CShapes7Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CShapes7Dlg::OnBnClickedCancel()
{
	CComboBox* pCombo = reinterpret_cast<CComboBox*>(GetDlgItem(IDC_COMBO1));
	int n = pCombo->GetCurSel(); // 0 for first item...
	const double pi = 3.14159;

	if (n == 0)
	{
		CString output;
		output.Format(_T("SQUARE side=%.2f area=%.2f perimeter=%.2f"), dim1, dim1 * dim1, dim1 * 4);
		GetDlgItem(IDC_EDIT7)->SetWindowText(output);
	}
	else if (n == 1)
	{
		CString output;
		output.Format(_T("CUBE side=%.2f surface area=%.2f volume=%.2f"), dim1, dim1 * dim1 * 6, dim1 * dim1 * dim1);
		GetDlgItem(IDC_EDIT7)->SetWindowText(output);
	}
	else if (n == 2)
	{
		CString output;
		output.Format(_T("RECTANGLE length=%.2f width=%.2f area=%.2f perimeter=%.2f"), dim1, dim2, dim1*dim2, (dim1 * 2) + (dim2 * 2));
		GetDlgItem(IDC_EDIT7)->SetWindowText(output);
	}
	else if (n == 3)
	{
		CString output;
		output.Format(_T("BOX length=%.2f width=%.2f height=%.2f surface area=%.2f volume=%.2f"), dim1, dim2, dim3, 2*(dim1*dim2 + dim1*dim3 + dim2*dim3), dim1*dim2*dim3);
		GetDlgItem(IDC_EDIT7)->SetWindowText(output);
	}
	else if (n == 4)
	{
		CString output;
		output.Format(_T("CIRCLE radius=%.2f area=%.2f perimeter=%.2f"), dim1, pi*dim1*dim1, dim1*2*pi);
		GetDlgItem(IDC_EDIT7)->SetWindowText(output);
	}
	else if (n == 5)
	{
		CString output;
		output.Format(_T("CYLINDER radius=%.2f height=%.2f surface area=%.2f volume=%.2f"), dim1, dim2, 2*pi*dim1*(dim1+dim2), pi*dim1*dim1*dim2);
		GetDlgItem(IDC_EDIT7)->SetWindowText(output);
	}
	else if (n == 6)
	{
		CString output;
		output.Format(_T("TRIANGLE side=%.2f area=%.2f perimeter=%.2f"), dim1, (sqrt(3)/4)*dim1*dim1,3*dim1);
		GetDlgItem(IDC_EDIT7)->SetWindowText(output);
	}
	else if (n == 7)
	{
		CString output;
		output.Format(_T("PRISM side=%.2f height=%.2f surface area=%.2f volume=%.2f"), dim1, dim2, dim1*dim1 + 2*dim1*dim2, 0.25*sqrt(3)*dim1*dim1*dim2);
		GetDlgItem(IDC_EDIT7)->SetWindowText(output);
	}
}

void CShapes7Dlg::OnEnChangeEdit1()
{
	CString strLength;
	GetDlgItem(IDC_EDIT1)->GetWindowText(strLength);
	dim1 = _ttof(strLength);
}


void CShapes7Dlg::OnEnChangeEdit2()
{
	CString strLength;
	GetDlgItem(IDC_EDIT2)->GetWindowText(strLength);
	dim2 = _ttof(strLength);
}


void CShapes7Dlg::OnEnChangeEdit3()
{
	CString strLength;
	GetDlgItem(IDC_EDIT3)->GetWindowText(strLength);
	dim3 = _ttof(strLength);
}

void CShapes7Dlg::OnCbnSelchangeCombo1()
{


	CComboBox* pCombo = reinterpret_cast<CComboBox*>(GetDlgItem(IDC_COMBO1));
	int n = pCombo->GetCurSel(); // 0 for first item...

	if (n == 0)
	{
		GetDlgItem(IDC_EDIT4)->SetWindowText(_T("Side"));
		GetDlgItem(IDC_EDIT5)->SetWindowText(_T("N/A"));
		GetDlgItem(IDC_EDIT6)->SetWindowText(_T("N/A"));
	}
	else if (n == 1)
	{
		GetDlgItem(IDC_EDIT4)->SetWindowText(_T("Side"));
		GetDlgItem(IDC_EDIT5)->SetWindowText(_T("N/A"));
		GetDlgItem(IDC_EDIT6)->SetWindowText(_T("N/A"));
	}
	else if (n == 2)
	{
		GetDlgItem(IDC_EDIT4)->SetWindowText(_T("Length"));
		GetDlgItem(IDC_EDIT5)->SetWindowText(_T("Width"));
		GetDlgItem(IDC_EDIT6)->SetWindowText(_T("N/A"));
	}
	else if (n == 3)
	{
		GetDlgItem(IDC_EDIT4)->SetWindowText(_T("Length"));
		GetDlgItem(IDC_EDIT5)->SetWindowText(_T("Width"));
		GetDlgItem(IDC_EDIT6)->SetWindowText(_T("Height"));
	}
	else if (n == 4)
	{
		GetDlgItem(IDC_EDIT4)->SetWindowText(_T("Radius"));
		GetDlgItem(IDC_EDIT5)->SetWindowText(_T("N/A"));
		GetDlgItem(IDC_EDIT6)->SetWindowText(_T("N/A"));
	}
	else if (n == 5)
	{
		GetDlgItem(IDC_EDIT4)->SetWindowText(_T("Radius"));
		GetDlgItem(IDC_EDIT5)->SetWindowText(_T("Height"));
		GetDlgItem(IDC_EDIT6)->SetWindowText(_T("N/A"));
	}
	else if (n == 6)
	{
		GetDlgItem(IDC_EDIT4)->SetWindowText(_T("Side"));
		GetDlgItem(IDC_EDIT5)->SetWindowText(_T("N/A"));
		GetDlgItem(IDC_EDIT6)->SetWindowText(_T("N/A"));
	}
	else if (n == 7)
	{
		GetDlgItem(IDC_EDIT4)->SetWindowText(_T("Side"));
		GetDlgItem(IDC_EDIT5)->SetWindowText(_T("Height"));
		GetDlgItem(IDC_EDIT6)->SetWindowText(_T("N/A"));
	}
	else if (n == 8)
	{
		GetDlgItem(IDC_EDIT4)->SetWindowText(_T(""));
		GetDlgItem(IDC_EDIT5)->SetWindowText(_T(""));
		GetDlgItem(IDC_EDIT6)->SetWindowText(_T(""));
	}
}

void CShapes7Dlg::OnEnChangeEdit4()
{
}


void CShapes7Dlg::OnEnChangeEdit5()
{
}


void CShapes7Dlg::OnEnChangeEdit6()
{
}


void CShapes7Dlg::OnEnChangeEdit7()
{
	
}
