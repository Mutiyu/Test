
// 八MFC一3View.cpp : C八MFC一3View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "八MFC一3.h"
#endif

#include "八MFC一3Doc.h"
#include "八MFC一3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C八MFC一3View

IMPLEMENT_DYNCREATE(C八MFC一3View, CView)

BEGIN_MESSAGE_MAP(C八MFC一3View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// C八MFC一3View 构造/析构

C八MFC一3View::C八MFC一3View()
{
	// TODO: 在此处添加构造代码
	//cr.left = 0;
	//cr.top = 433 - 40;
	//cr.right = 100;
	//cr.bottom = 433 + 60;
	set = false;
	set1 = false;
	t = 0;
}

C八MFC一3View::~C八MFC一3View()
{
}

BOOL C八MFC一3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C八MFC一3View 绘制

void C八MFC一3View::OnDraw(CDC* pDC)
{
	C八MFC一3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	GetClientRect(&client);
	cr.left = 0;
	cr.top = (client.bottom-client.top)/2 - 40;
	cr.right = 100;
	cr.bottom = (client.bottom - client.top) / 2 + 60;
SetTimer(1, 500, NULL);

	if (set1)
	{
		KillTimer(1);
	    cr.left = client.right - 100;
		cr.right = client.right;
 		SetTimer(2, 500, NULL);
	}
	
pDC->Ellipse(cr.left + t, cr.top, cr.right + t, cr.bottom);

	// TODO: 在此处为本机数据添加绘制代码
}


// C八MFC一3View 打印

BOOL C八MFC一3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C八MFC一3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C八MFC一3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C八MFC一3View 诊断

#ifdef _DEBUG
void C八MFC一3View::AssertValid() const
{
	CView::AssertValid();
}

void C八MFC一3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C八MFC一3Doc* C八MFC一3View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C八MFC一3Doc)));
	return (C八MFC一3Doc*)m_pDocument;
}
#endif //_DEBUG


// C八MFC一3View 消息处理程序


void C八MFC一3View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	switch (nIDEvent)
	{
	case 1:
		if(set)
		{
if (t <= (client.right -cr.right))
		{
	     t+= 50;
		}
else
           {
	set1 = true;
	t = 0;
		   }
			
	}

break;
	case 2:
		if (set)
		{
			
			t -= 50;
		}
			
			break;
	
	}
		
    Invalidate();
	CView::OnTimer(nIDEvent);
}


void C八MFC一3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	set = true;
	CView::OnLButtonDown(nFlags, point);
}


void C八MFC一3View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	set = false;
	CView::OnLButtonDblClk(nFlags, point);
}
