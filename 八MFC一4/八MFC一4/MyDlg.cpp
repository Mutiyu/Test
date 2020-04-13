// MyDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "八MFC一4.h"
#include "MyDlg.h"
#include "afxdialogex.h"


// MyDlg 对话框

IMPLEMENT_DYNAMIC(MyDlg, CDialogEx)

MyDlg::MyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, s1(_T(""))
	, x(0)
	, s3(_T(""))
{

}

MyDlg::~MyDlg()
{
}

void MyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, s1);
	DDX_Text(pDX, IDC_EDIT2, x);
	DDX_Text(pDX, IDC_EDIT3, s3);
}


BEGIN_MESSAGE_MAP(MyDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT2, &MyDlg::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON1, &MyDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// MyDlg 消息处理程序


void MyDlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void MyDlg::OnBnClickedButton1()
{
	this->UpdateData(true);
	CString s2;
	int X = x;
	s2.Format(_T("%d"), X);
		
		s3 = s1 +s2;
		this->UpdateData(false);
}
