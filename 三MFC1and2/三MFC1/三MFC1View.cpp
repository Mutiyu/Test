
// 三MFC1View.cpp : C三MFC1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "三MFC1.h"
#endif

#include "三MFC1Doc.h"
#include "三MFC1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C三MFC1View

IMPLEMENT_DYNCREATE(C三MFC1View, CView)

BEGIN_MESSAGE_MAP(C三MFC1View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// C三MFC1View 构造/析构

C三MFC1View::C三MFC1View()
{
	// TODO: 在此处添加构造代码

}

C三MFC1View::~C三MFC1View()
{
}

BOOL C三MFC1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C三MFC1View 绘制

void C三MFC1View::OnDraw(CDC* pDC)
{
	C三MFC1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	// TODO: 在此处为本机数据添加绘制代码
	int a = pDoc->A;
	int b = pDoc->B;
	cn.Format(_T("A+B=%d"), a + b);


}


// C三MFC1View 诊断

#ifdef _DEBUG
void C三MFC1View::AssertValid() const
{
	CView::AssertValid();
}

void C三MFC1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C三MFC1Doc* C三MFC1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C三MFC1Doc)));
	return (C三MFC1Doc*)m_pDocument;
}
#endif //_DEBUG


// C三MFC1View 消息处理程序


void C三MFC1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString cs;
	cs.Format(_T("左键正在被按下"));
	CClientDC dc(this);
	dc.TextOutW(100,200,cs);
	dc.TextOutW(130, 400, cn);
	CView::OnLButtonDown(nFlags, point);
}


void C三MFC1View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString s;
	s.Format(_T("左键正在抬起"));
	CClientDC dc(this);
	dc.TextOutW(300, 200, s);
	CView::OnLButtonUp(nFlags, point);
}
