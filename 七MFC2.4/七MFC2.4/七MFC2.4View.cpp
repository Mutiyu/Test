
// 七MFC2.4View.cpp : C七MFC24View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "七MFC2.4.h"
#endif

#include "七MFC2.4Doc.h"
#include "七MFC2.4View.h"
#include"MyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C七MFC24View

IMPLEMENT_DYNCREATE(C七MFC24View, CView)

BEGIN_MESSAGE_MAP(C七MFC24View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_popDlg, &C七MFC24View::Onpopdlg)
END_MESSAGE_MAP()

// C七MFC24View 构造/析构

C七MFC24View::C七MFC24View()
{
	// TODO: 在此处添加构造代码
	cr.left = 200; cr.top = 200;
	cr.right = 560; cr.bottom =740;
	set = false;
	A = B = C = 0;
}

C七MFC24View::~C七MFC24View()
{
}

BOOL C七MFC24View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C七MFC24View 绘制

void C七MFC24View::OnDraw(CDC* pDC)
{
	C七MFC24Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Ellipse(cr);
	/*if (set)

	{
   rgn.CreateEllipticRgn(200, 200, 560, 740);
	brush.CreateSolidBrush(RGB(A, B, C));
	pDC->FillRgn(&rgn, &brush);
	}*/
	
	
	// TODO: 在此处为本机数据添加绘制代码
}


// C七MFC24View 打印

BOOL C七MFC24View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C七MFC24View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C七MFC24View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C七MFC24View 诊断

#ifdef _DEBUG
void C七MFC24View::AssertValid() const
{
	CView::AssertValid();
}

void C七MFC24View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C七MFC24Doc* C七MFC24View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C七MFC24Doc)));
	return (C七MFC24Doc*)m_pDocument;
}
#endif //_DEBUG


// C七MFC24View 消息处理程序


void C七MFC24View::Onpopdlg()
{
	// TODO: 在此添加命令处理程序代码
	MyDlg dlg;
	int t=dlg.DoModal();
	if (t == IDOK)
	{
		set = true;
		A = dlg.a;
		B = dlg.b;
		C = dlg.c;
		rgn.CreateEllipticRgn(200, 200, 560, 740);
		brush.CreateSolidBrush(RGB(A, B, C));
		GetDC()->FillRgn(&rgn, &brush);
	}
}
