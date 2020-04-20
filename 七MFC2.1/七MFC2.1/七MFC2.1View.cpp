
// 七MFC2.1View.cpp : C七MFC21View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "七MFC2.1.h"
#endif

#include "七MFC2.1Doc.h"
#include "七MFC2.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C七MFC21View

IMPLEMENT_DYNCREATE(C七MFC21View, CView)

BEGIN_MESSAGE_MAP(C七MFC21View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// C七MFC21View 构造/析构

C七MFC21View::C七MFC21View()
{
	// TODO: 在此处添加构造代码
	set = false;
	cr.left = 100; cr.top = 230;
	cr.right = 330; cr.bottom = 480;
	x1 = x2 = y1 = y2 = 0;
}

C七MFC21View::~C七MFC21View()
{
}

BOOL C七MFC21View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C七MFC21View 绘制

void C七MFC21View::OnDraw(CDC* pDC)
{
	C七MFC21Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Ellipse(cr);
	// TODO: 在此处为本机数据添加绘制代码
}


// C七MFC21View 打印

BOOL C七MFC21View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C七MFC21View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C七MFC21View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C七MFC21View 诊断

#ifdef _DEBUG
void C七MFC21View::AssertValid() const
{
	CView::AssertValid();
}

void C七MFC21View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C七MFC21Doc* C七MFC21View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C七MFC21Doc)));
	return (C七MFC21Doc*)m_pDocument;
}
#endif //_DEBUG


// C七MFC21View 消息处理程序


void C七MFC21View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	set = true;
	cp = point;
	x1 = point.x - cr.left;
	x2 = cr.right - point.x;
	y1 = point.y-cr.top ;
	y2 = cr.bottom - point.y;
	CView::OnLButtonDown(nFlags, point);
}


void C七MFC21View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	set = false;
	CView::OnLButtonUp(nFlags, point);
}


void C七MFC21View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (set)
	{
		cr.left = point.x - x1;
		cr.right = point.x + x2;
		cr.top = point.y - y1;
		cr.bottom = point.y + y2;
		
	}
	Invalidate();
	CView::OnMouseMove(nFlags, point);
}
