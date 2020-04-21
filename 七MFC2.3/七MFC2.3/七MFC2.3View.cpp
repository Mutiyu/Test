
// 七MFC2.3View.cpp : C七MFC23View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "七MFC2.3.h"
#endif

#include "七MFC2.3Doc.h"
#include "七MFC2.3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C七MFC23View

IMPLEMENT_DYNCREATE(C七MFC23View, CView)

BEGIN_MESSAGE_MAP(C七MFC23View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// C七MFC23View 构造/析构

C七MFC23View::C七MFC23View()
{
	// TODO: 在此处添加构造代码
	cr.left = 200; cr.top = 100;
	cr.right = 400; cr.bottom = 400;
	m_bDashLine =false;
	set = false;
}

C七MFC23View::~C七MFC23View()
{
}

BOOL C七MFC23View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C七MFC23View 绘制

void C七MFC23View::OnDraw(CDC* pDC)
{
	C七MFC23Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Ellipse(cr);
	CPen *oldpen = NULL;
	CPen pen(PS_DASH, 1, RGB(255, 0, 0));
	GetDC()->SelectStockObject(NULL_BRUSH);
	CBrush *oldbrush = NULL;
	CBrush *brush=CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
	oldbrush = pDC->SelectObject(brush);
	if (set)
	{
			//CreatePen(PS_DASH, 0,RGB(255,0,0));
			oldpen = pDC->SelectObject(&pen);
			pDC->Rectangle(cr);
			pDC->SelectObject(oldpen);

	}
	// TODO: 在此处为本机数据添加绘制代码
}


// C七MFC23View 打印

BOOL C七MFC23View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C七MFC23View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C七MFC23View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C七MFC23View 诊断

#ifdef _DEBUG
void C七MFC23View::AssertValid() const
{
	CView::AssertValid();
}

void C七MFC23View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C七MFC23Doc* C七MFC23View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C七MFC23Doc)));
	return (C七MFC23Doc*)m_pDocument;
}
#endif //_DEBUG


// C七MFC23View 消息处理程序


void C七MFC23View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC  dc(this);
	m_bDashLine = true;
	CPen *oldpen = NULL;
	CPen pen(PS_DASH, 1, RGB(255, 0, 0));
	GetDC()->SelectStockObject(NULL_BRUSH);
	CBrush *oldbrush = NULL;
	CBrush *brush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
	oldbrush =dc.SelectObject(brush);
	if (point.x > cr.left&&point.x < cr.right)
	{
		if (point.y > cr.top&&point.y < cr.bottom)
		{
				//CreatePen(PS_DASH, 0,RGB(255,0,0));
				oldpen = dc.SelectObject(&pen);
				dc.Rectangle(cr);
				dc.SelectObject(oldpen);
			
	   }
	}
	//Invalidate();
	CView::OnLButtonDown(nFlags, point);
}
