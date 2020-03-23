
// 五MFC1View.cpp : C五MFC1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "五MFC1.h"
#endif

#include "五MFC1Doc.h"
#include "五MFC1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C五MFC1View

IMPLEMENT_DYNCREATE(C五MFC1View, CView)

BEGIN_MESSAGE_MAP(C五MFC1View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_ShowCircle, &C五MFC1View::OnShowcircle)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// C五MFC1View 构造/析构

C五MFC1View::C五MFC1View()
{
	// TODO: 在此处添加构造代码
	set = false;
	t = 0;
	
}

C五MFC1View::~C五MFC1View()
{
}

BOOL C五MFC1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C五MFC1View 绘制

void C五MFC1View::OnDraw(CDC* pDC)
{
	C五MFC1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
    SetTimer(1, 500, NULL);
	GetClientRect(&cr);
	cp = cr.CenterPoint();
	cr.left = cp.x - 25; cr.top = cp.y - 25;
	cr.right = cp.x + 25; cr.bottom = cp.y + 25;
	if (set)
	{   
		pDC->Ellipse(cr.left -= t, cr.top -= t, cr.right += t, cr.bottom += t);
	}
	// TODO: 在此处为本机数据添加绘制代码
}


// C五MFC1View 打印

BOOL C五MFC1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C五MFC1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C五MFC1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C五MFC1View 诊断

#ifdef _DEBUG
void C五MFC1View::AssertValid() const
{
	CView::AssertValid();
}

void C五MFC1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C五MFC1Doc* C五MFC1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C五MFC1Doc)));
	return (C五MFC1Doc*)m_pDocument;
}
#endif //_DEBUG


// C五MFC1View 消息处理程序


void C五MFC1View::OnShowcircle()
{
	// TODO: 在此添加命令处理程序代码
	set = true;
	
}


void C五MFC1View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	     t += 5;
		Invalidate();
		
	CView::OnTimer(nIDEvent);
}
