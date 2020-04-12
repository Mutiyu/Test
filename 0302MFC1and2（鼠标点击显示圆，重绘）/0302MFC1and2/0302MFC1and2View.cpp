
// 0302MFC1and2View.cpp : CMy0302MFC1and2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0302MFC1and2.h"
#endif

#include "0302MFC1and2Doc.h"
#include "0302MFC1and2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0302MFC1and2View

IMPLEMENT_DYNCREATE(CMy0302MFC1and2View, CView)

BEGIN_MESSAGE_MAP(CMy0302MFC1and2View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy0302MFC1and2View 构造/析构

CMy0302MFC1and2View::CMy0302MFC1and2View()
{
	// TODO: 在此处添加构造代码

}

CMy0302MFC1and2View::~CMy0302MFC1and2View()
{
}

BOOL CMy0302MFC1and2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy0302MFC1and2View 绘制

void CMy0302MFC1and2View::OnDraw(CDC* pDC)
{
	CMy0302MFC1and2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Ellipse(cr);
	// TODO: 在此处为本机数据添加绘制代码
}


// CMy0302MFC1and2View 打印

BOOL CMy0302MFC1and2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy0302MFC1and2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy0302MFC1and2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy0302MFC1and2View 诊断

#ifdef _DEBUG
void CMy0302MFC1and2View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0302MFC1and2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0302MFC1and2Doc* CMy0302MFC1and2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0302MFC1and2Doc)));
	return (CMy0302MFC1and2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0302MFC1and2View 消息处理程序


void CMy0302MFC1and2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int r = rand() % 100 + 50;
	cr.left = point.x - r; cr.top = point.y - r;
	cr.right = point.x + r;   cr.bottom = point.y + r;
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}
