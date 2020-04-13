
// Exp1View.cpp : CExp1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Exp1.h"
#endif

#include "Exp1Doc.h"
#include "Exp1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExp1View

IMPLEMENT_DYNCREATE(CExp1View, CView)

BEGIN_MESSAGE_MAP(CExp1View, CView)
END_MESSAGE_MAP()

// CExp1View 构造/析构

CExp1View::CExp1View()
{
	// TODO: 在此处添加构造代码
	

}

CExp1View::~CExp1View()
{
}

BOOL CExp1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CExp1View 绘制

void CExp1View::OnDraw(CDC* pDC)
{
	CExp1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString  s1,A1;
	s1 = _T("我是小余");
	
	int h1;
	h1= 91;
	A1.Format(_T("A1的值为%d"),h1);
	pDC->TextOutW(100, 200, _T("View类："));
	pDC->TextOutW( 300,200,s1);
	pDC->TextOutW( 600,200,A1);
	pDC->TextOutW(100, 400, _T("Doc类："));
	pDC->TextOutW( 300,400,pDoc->s2);
	pDC->TextOutW( 600,400,pDoc->A2);
	// TODO: 在此处为本机数据添加绘制代码
}


// CExp1View 诊断

#ifdef _DEBUG
void CExp1View::AssertValid() const
{
	CView::AssertValid();
}

void CExp1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExp1Doc* CExp1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExp1Doc)));
	return (CExp1Doc*)m_pDocument;
}
#endif //_DEBUG


// CExp1View 消息处理程序
