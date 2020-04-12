
// 四MFC1View.cpp : C四MFC1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "四MFC1.h"
#endif

#include "四MFC1Doc.h"
#include "四MFC1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C四MFC1View

IMPLEMENT_DYNCREATE(C四MFC1View, CView)

BEGIN_MESSAGE_MAP(C四MFC1View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// C四MFC1View 构造/析构

C四MFC1View::C四MFC1View()
{
	// TODO: 在此处添加构造代码

}

C四MFC1View::~C四MFC1View()
{
}

BOOL C四MFC1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C四MFC1View 绘制

void C四MFC1View::OnDraw(CDC* pDC)
{
	C四MFC1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	// TODO: 在此处为本机数据添加绘制代码
}


// C四MFC1View 诊断

#ifdef _DEBUG
void C四MFC1View::AssertValid() const
{
	CView::AssertValid();
}

void C四MFC1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C四MFC1Doc* C四MFC1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C四MFC1Doc)));
	return (C四MFC1Doc*)m_pDocument;
}
#endif //_DEBUG


// C四MFC1View 消息处理程序


void C四MFC1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	C四MFC1Doc* pDoc = GetDocument();
	
	pDoc->a = point.x;
	pDoc->b = point.y;
	

	CView::OnLButtonDown(nFlags, point);
}


void C四MFC1View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	C四MFC1Doc* pDoc = GetDocument();
	CString s;
	s.Format(_T("x=%d    y=%d"), point.x, point.y);
	CClientDC dc(this);
	dc.TextOutW(20, 20, s);
	CView::OnMouseMove(nFlags, point);
}


void C四MFC1View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	C四MFC1Doc* pDoc = GetDocument();
	pDoc->c = point.x;
	pDoc->d = point.y;
	pDoc->cr.left = pDoc->a; pDoc->cr.top = pDoc->b;
	pDoc->cr.right = pDoc->c; pDoc->cr.bottom = pDoc->d;
	CClientDC dc(this);
	dc.Rectangle(pDoc->cr);
	CView::OnLButtonUp(nFlags, point);
}
