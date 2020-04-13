
// 四MFC2View.cpp : C四MFC2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "四MFC2.h"
#endif

#include "四MFC2Doc.h"
#include "四MFC2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C四MFC2View

IMPLEMENT_DYNCREATE(C四MFC2View, CView)

BEGIN_MESSAGE_MAP(C四MFC2View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// C四MFC2View 构造/析构

C四MFC2View::C四MFC2View()
{
	// TODO: 在此处添加构造代码
	M = 0;
	N = 0;
	cr.left = 0; cr.top = 0;
	cr.right = 0; cr.bottom = 0;
	a = 0; b = 0;
}

C四MFC2View::~C四MFC2View()
{
}

BOOL C四MFC2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C四MFC2View 绘制

void C四MFC2View::OnDraw(CDC* pDC)
{
	C四MFC2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: 在此处为本机数据添加绘制代码
	//int a = cr.Width();
	

}


// C四MFC2View 诊断

#ifdef _DEBUG
void C四MFC2View::AssertValid() const
{
	CView::AssertValid();
}

void C四MFC2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C四MFC2Doc* C四MFC2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C四MFC2Doc)));
	return (C四MFC2Doc*)m_pDocument;
}
#endif //_DEBUG


// C四MFC2View 消息处理程序


void C四MFC2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	set = true;
	cr.left = point.x;
	cr.top = point.y;
	CView::OnLButtonDown(nFlags, point);
}

void C四MFC2View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	set = false;
	 M = N;
	  N = 0;
	  CString t;
	CClientDC dc(this);
	cr.right = point.x;
	cr.bottom = point.y;
	a = cr.Width();
	t.Format(_T("横向移动  %d   个像素发生一次"), a / M);
	dc.TextOutW(40, 40, t);
	CView::OnLButtonUp(nFlags, point);
}

void C四MFC2View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CString s,t;
	if (set) {
		N += nFlags;
		CString s, t;
		s.Format(_T("MouseMove发生了   %d    次"), N);
		dc.TextOutW(20, 20, s);
		
		}
	//b = a /N ;
		//t.Format(_T("横向移动  %d   个像素发生一次"),a);
		//dc.TextOutW(40, 80, t);
	
       
	
	CView::OnMouseMove(nFlags, point);
}



