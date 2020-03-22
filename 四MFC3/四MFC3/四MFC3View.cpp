
// 四MFC3View.cpp : C四MFC3View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "四MFC3.h"
#endif

#include "四MFC3Doc.h"
#include "四MFC3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C四MFC3View

IMPLEMENT_DYNCREATE(C四MFC3View, CView)

BEGIN_MESSAGE_MAP(C四MFC3View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_KEYDOWN()
	ON_WM_CHAR()
END_MESSAGE_MAP()

// C四MFC3View 构造/析构

C四MFC3View::C四MFC3View()
{
	// TODO: 在此处添加构造代码
	cr.left = 300; cr.top =360;
	cr.right = 200; cr.bottom =250;
}

C四MFC3View::~C四MFC3View()
{
}

BOOL C四MFC3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C四MFC3View 绘制

void C四MFC3View::OnDraw(CDC* pDC)
{
	C四MFC3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(cr);
	// TODO: 在此处为本机数据添加绘制代码
}


// C四MFC3View 打印

BOOL C四MFC3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C四MFC3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C四MFC3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C四MFC3View 诊断

#ifdef _DEBUG
void C四MFC3View::AssertValid() const
{
	CView::AssertValid();
}

void C四MFC3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C四MFC3Doc* C四MFC3View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C四MFC3Doc)));
	return (C四MFC3Doc*)m_pDocument;
}
#endif //_DEBUG


// C四MFC3View 消息处理程序


void C四MFC3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	cr.left = 300; cr.top = 360;
	cr.right = 200; cr.bottom = 250;
	InvalidateRect(NULL, TRUE);
	CView::OnLButtonDown(nFlags, point);
}


void C四MFC3View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CRect clientRec;
	GetClientRect(&clientRec);
	switch (nChar)
	{
	case VK_LEFT:
		if (cr.left > 0)
		{
			cr.left -= 5;
			cr.right -= 5;
		} break;
	case VK_RIGHT:
		if (cr.right > 0)
		{
			cr.right += 5;
			cr.left += 5;
		}break;
	case VK_UP:
		if (cr.top > 0)
		{
			cr.top -= 5;
			cr.bottom -= 5;
		}break;
	case VK_DOWN:
		cr.top += 5;
		cr.bottom += 5;
		break;
	}


	InvalidateRect(NULL, TRUE);

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void C四MFC3View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CRect clientRec;
	GetClientRect(&clientRec);
	switch (nChar)
	{
	case 'a':
		if (cr.left > 0 && cr.top > 0)
		{
			cr.left -= 20;
			cr.top -= 20;
		}break;
	case 'b':
		if (cr.right <= (clientRec.right - clientRec.left))
		{
			cr.left += 20;
			cr.top += 20;

		}break;

	}
	InvalidateRect(NULL, TRUE);
	CView::OnChar(nChar, nRepCnt, nFlags);
}
