
// 八MFC一1View.cpp : C八MFC一1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "八MFC一1.h"
#endif

#include "八MFC一1Doc.h"
#include "八MFC一1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C八MFC一1View

IMPLEMENT_DYNCREATE(C八MFC一1View, CView)

BEGIN_MESSAGE_MAP(C八MFC一1View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// C八MFC一1View 构造/析构

C八MFC一1View::C八MFC一1View()
{
	// TODO: 在此处添加构造代码
	cr.left = 100; cr.top = 150;
	cr.right = 400; cr.bottom = 500;
	set = false;
	x1 = x2 = y1 = y2 = 0;
}

C八MFC一1View::~C八MFC一1View()
{
}

BOOL C八MFC一1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C八MFC一1View 绘制

void C八MFC一1View::OnDraw(CDC* pDC)
{
	C八MFC一1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(cr);
	// TODO: 在此处为本机数据添加绘制代码
}


// C八MFC一1View 打印

BOOL C八MFC一1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C八MFC一1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C八MFC一1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C八MFC一1View 诊断

#ifdef _DEBUG
void C八MFC一1View::AssertValid() const
{
	CView::AssertValid();
}

void C八MFC一1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C八MFC一1Doc* C八MFC一1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C八MFC一1Doc)));
	return (C八MFC一1Doc*)m_pDocument;
}
#endif //_DEBUG


// C八MFC一1View 消息处理程序


void C八MFC一1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	set = true;
	dMove = point;
	x1 = point.x - cr.left;
	x2 = cr.right - point.x;
	y1 = point.y - cr.top;
	y2 = cr.bottom - point.y;
	CView::OnLButtonDown(nFlags, point);
}


void C八MFC一1View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	set = false;
	CView::OnLButtonUp(nFlags, point);
}


void C八MFC一1View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (set)
	{
		mMove = point;
		cr.left = mMove.x - x1;
		cr.top = mMove.y - y1;
		cr.right = mMove.x + x2;
		cr.bottom = mMove.y + y2;
	}
	Invalidate();
	CView::OnMouseMove(nFlags, point);
}
