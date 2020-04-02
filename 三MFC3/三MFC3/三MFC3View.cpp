
// 三MFC3View.cpp : C三MFC3View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "三MFC3.h"
#endif

#include "三MFC3Doc.h"
#include "三MFC3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C三MFC3View

IMPLEMENT_DYNCREATE(C三MFC3View, CView)

BEGIN_MESSAGE_MAP(C三MFC3View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// C三MFC3View 构造/析构

C三MFC3View::C三MFC3View()
{
	// TODO: 在此处添加构造代码
	
}

C三MFC3View::~C三MFC3View()
{
}

BOOL C三MFC3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C三MFC3View 绘制

void C三MFC3View::OnDraw(CDC* pDC)
{
	C三MFC3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(pDoc->a);
	pDC->Rectangle(pDoc->b);
	pDC->Rectangle(pDoc->c);
	// TODO: 在此处为本机数据添加绘制代码
}


// C三MFC3View 打印

BOOL C三MFC3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C三MFC3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C三MFC3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C三MFC3View 诊断

#ifdef _DEBUG
void C三MFC3View::AssertValid() const
{
	CView::AssertValid();
}

void C三MFC3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C三MFC3Doc* C三MFC3View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C三MFC3Doc)));
	return (C三MFC3Doc*)m_pDocument;
}
#endif //_DEBUG


// C三MFC3View 消息处理程序


void C三MFC3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	if (point.x >= 100 && point.x <= 300&&point.y >= 100 && point.y <= 400)
	{
		
			a = rand() % 100;
			s1.Format(_T("%d"), a);
			dc.TextOutW(point.x, point.y, s1);
		    
	}
	else if (point.x >= 400 && point.x <= 700&&point.y >= 400 && point.y <= 550)
	{
			b = rand() % 100;
			s2.Format(_T("%d"), b);
			dc.TextOutW(point.x, point.y, s2);
	}
	else
	{
		dc.TextOutW(point.x, point.y, _T("点击无效"));
	}
	CView::OnLButtonDown(nFlags, point);
}


void C三MFC3View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	if (point.x >= 900 && point.x <= 1050 && point.y >= 200 && point.y <= 500)
	{
		a = rand() % 100;
		b = rand() % 100;
		c = a + b;
		s3.Format(_T("%d", c));
		dc.TextOutW(point.x, point.y, s3);
	}
	CView::OnRButtonDown(nFlags, point);
}
