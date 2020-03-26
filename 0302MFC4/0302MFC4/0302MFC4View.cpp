
// 0302MFC4View.cpp : CMy0302MFC4View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0302MFC4.h"
#endif

#include "0302MFC4Doc.h"
#include "0302MFC4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0302MFC4View

IMPLEMENT_DYNCREATE(CMy0302MFC4View, CView)

BEGIN_MESSAGE_MAP(CMy0302MFC4View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMy0302MFC4View 构造/析构

CMy0302MFC4View::CMy0302MFC4View()
{
	// TODO: 在此处添加构造代码

}

CMy0302MFC4View::~CMy0302MFC4View()
{
}

BOOL CMy0302MFC4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy0302MFC4View 绘制

void CMy0302MFC4View::OnDraw(CDC* pDC)
{
	CMy0302MFC4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	rgn.CreateEllipticRgn( 200, 200, 560, 740);
	cb.CreateSolidBrush(RGB(255, 192, 203));
	pDC->FillRgn( &rgn, &cb);
	pDC->Ellipse(cr);
	// TODO: 在此处为本机数据添加绘制代码
}


// CMy0302MFC4View 打印

BOOL CMy0302MFC4View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy0302MFC4View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy0302MFC4View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy0302MFC4View 诊断

#ifdef _DEBUG
void CMy0302MFC4View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0302MFC4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0302MFC4Doc* CMy0302MFC4View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0302MFC4Doc)));
	return (CMy0302MFC4Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0302MFC4View 消息处理程序
