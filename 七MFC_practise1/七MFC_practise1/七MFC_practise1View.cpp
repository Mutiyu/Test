
// 七MFC_practise1View.cpp : C七MFC_practise1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "七MFC_practise1.h"
#endif

#include "七MFC_practise1Doc.h"
#include "七MFC_practise1View.h"
#include "MyDlg1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C七MFC_practise1View

IMPLEMENT_DYNCREATE(C七MFC_practise1View, CView)

BEGIN_MESSAGE_MAP(C七MFC_practise1View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CLOSE()
END_MESSAGE_MAP()

// C七MFC_practise1View 构造/析构

C七MFC_practise1View::C七MFC_practise1View()
{
	// TODO: 在此处添加构造代码
	
}

C七MFC_practise1View::~C七MFC_practise1View()
{
}

BOOL C七MFC_practise1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C七MFC_practise1View 绘制

void C七MFC_practise1View::OnDraw(CDC* pDC)
{
	C七MFC_practise1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	MyDlg1 dlg;
	int r = dlg.DoModal();
	if (r == IDOK)
	{
		pDC->TextOutW(400, 350, _T("你已退出对话框"));
		
	}
	
	// TODO: 在此处为本机数据添加绘制代码
}


// C七MFC_practise1View 打印

BOOL C七MFC_practise1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C七MFC_practise1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C七MFC_practise1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C七MFC_practise1View 诊断

#ifdef _DEBUG
void C七MFC_practise1View::AssertValid() const
{
	CView::AssertValid();
}

void C七MFC_practise1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C七MFC_practise1Doc* C七MFC_practise1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C七MFC_practise1Doc)));
	return (C七MFC_practise1Doc*)m_pDocument;
}
#endif //_DEBUG


// C七MFC_practise1View 消息处理程序


void C七MFC_practise1View::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	CView::OnClose();
}
