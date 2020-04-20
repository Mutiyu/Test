
// 七MFC2.2View.cpp : C七MFC22View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "七MFC2.2.h"
#endif

#include "七MFC2.2Doc.h"
#include "七MFC2.2View.h"
#include"MyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C七MFC22View

IMPLEMENT_DYNCREATE(C七MFC22View, CView)

BEGIN_MESSAGE_MAP(C七MFC22View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_popDlg, &C七MFC22View::Onpopdlg)
END_MESSAGE_MAP()

// C七MFC22View 构造/析构

C七MFC22View::C七MFC22View()
{
	// TODO: 在此处添加构造代码
	Vset = false;
	X = 0.0;
	Y = 0.0;
}

C七MFC22View::~C七MFC22View()
{
}

BOOL C七MFC22View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C七MFC22View 绘制

void C七MFC22View::OnDraw(CDC* pDC)
{
	C七MFC22Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Ellipse(cr);
	
	// TODO: 在此处为本机数据添加绘制代码
}


// C七MFC22View 打印

BOOL C七MFC22View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C七MFC22View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C七MFC22View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C七MFC22View 诊断

#ifdef _DEBUG
void C七MFC22View::AssertValid() const
{
	CView::AssertValid();
}

void C七MFC22View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C七MFC22Doc* C七MFC22View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C七MFC22Doc)));
	return (C七MFC22Doc*)m_pDocument;
}
#endif //_DEBUG


// C七MFC22View 消息处理程序


void C七MFC22View::Onpopdlg()
{
	// TODO: 在此添加命令处理程序代码
	Vset = true;
	MyDlg dlg;
	int t=dlg.DoModal();
		X = dlg.x;
		Y = dlg.y;
		cr.left = 500 - X / 2;
		cr.top = 500 - Y / 2;
		cr.right = 500 + X / 2;
		cr.bottom = 500 + Y / 2;
	
	if (t==IDOK)
	{
		GetDC()->Ellipse(cr);
	}
	Invalidate();
}
