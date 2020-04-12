
// 五MFC二1View.cpp : C五MFC二1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "五MFC二1.h"
#endif

#include "五MFC二1Doc.h"
#include "五MFC二1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C五MFC二1View

IMPLEMENT_DYNCREATE(C五MFC二1View, CView)

BEGIN_MESSAGE_MAP(C五MFC二1View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_ShowMyName, &C五MFC二1View::OnShowmyname)
	ON_COMMAND(ID_ShowLine, &C五MFC二1View::OnShowline)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_Rectangle, &C五MFC二1View::OnRectangle)
	ON_COMMAND(ID_circle, &C五MFC二1View::Oncircle)
END_MESSAGE_MAP()

// C五MFC二1View 构造/析构

C五MFC二1View::C五MFC二1View()
{
	// TODO: 在此处添加构造代码
	BITMAP BM;
	cb.LoadBitmap(IDB_BITMAP1);
	cb.GetBitmap(&BM);
	c_Width= BM.bmWidth;
	c_Height = BM.bmHeight;
	set1 = false;
	set2 = false;
	set3 = false;



}

C五MFC二1View::~C五MFC二1View()
{
}

BOOL C五MFC二1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C五MFC二1View 绘制

void C五MFC二1View::OnDraw(CDC* pDC)
{
	C五MFC二1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CDC MepDC;
	MepDC.CreateCompatibleDC(NULL);
	MepDC.SelectObject(cb);
	pDC->BitBlt(0, 0, c_Width, c_Height, &MepDC, 0, 0, SRCCOPY);
	// TODO: 在此处为本机数据添加绘制代码
}


// C五MFC二1View 打印

BOOL C五MFC二1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C五MFC二1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C五MFC二1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C五MFC二1View 诊断

#ifdef _DEBUG
void C五MFC二1View::AssertValid() const
{
	CView::AssertValid();
}

void C五MFC二1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C五MFC二1Doc* C五MFC二1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C五MFC二1Doc)));
	return (C五MFC二1Doc*)m_pDocument;
}
#endif //_DEBUG


// C五MFC二1View 消息处理程序


void C五MFC二1View::OnShowmyname()
{
	// TODO: 在此添加命令处理程序代码
	CString s;
	s.Format(_T("余妙琳"));
	CClientDC dc(this);
	dc.TextOutW(600, 500, s);

}


void C五MFC二1View::OnShowline()
{
	set1 = true;
	set2 = false;
	set3 = false;
}


void C五MFC二1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	d = point;
	cr.left = point.x;
	cr.top = point.y;
	CView::OnLButtonDown(nFlags, point);
}


void C五MFC二1View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	u = point;
	if (set1)
	{
		dc.MoveTo(d);
		dc.LineTo(point);
	}
	if (set2) {
		dc.Rectangle(cr.left,cr.top,point.x,point.y);
	}
	if (set3)
	{
		dc.Ellipse(cr.left, cr.top, point.x, point.y);
	}
	CView::OnLButtonUp(nFlags, point);
}


void C五MFC二1View::OnRectangle()
{
	set1 = false;
	set2 = true;
}


void C五MFC二1View::Oncircle()
{
	set1 = false;
	set2 = false;
	set3 = true;

}
