
// 二MFC3View.cpp : C二MFC3View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "二MFC3.h"
#endif

#include "二MFC3Doc.h"
#include "二MFC3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C二MFC3View

IMPLEMENT_DYNCREATE(C二MFC3View, CView)

BEGIN_MESSAGE_MAP(C二MFC3View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// C二MFC3View 构造/析构

C二MFC3View::C二MFC3View()
{
	// TODO: 在此处添加构造代码

}

C二MFC3View::~C二MFC3View()
{
}

BOOL C二MFC3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C二MFC3View 绘制

void C二MFC3View::OnDraw(CDC* /*pDC*/)
{
	C二MFC3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C二MFC3View 打印

BOOL C二MFC3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C二MFC3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C二MFC3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C二MFC3View 诊断

#ifdef _DEBUG
void C二MFC3View::AssertValid() const
{
	CView::AssertValid();
}

void C二MFC3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C二MFC3Doc* C二MFC3View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C二MFC3Doc)));
	return (C二MFC3Doc*)m_pDocument;
}
#endif //_DEBUG


// C二MFC3View 消息处理程序


void C二MFC3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	C二MFC3Doc* pDoc = GetDocument();
	pDoc->count += nFlags;
	CView::OnLButtonDown(nFlags, point);
}


void C二MFC3View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	C二MFC3Doc* pDoc = GetDocument();
	CString s;
	s.Format(_T("count=%d"), pDoc->count);
	CClientDC dc(this);
	dc.TextOutW(300, 300, s);
	CView::OnRButtonDown(nFlags, point);
}
