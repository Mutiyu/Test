
// 七MFC_practise2View.cpp : C七MFC_practise2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "七MFC_practise2.h"
#endif

#include "七MFC_practise2Doc.h"
#include "七MFC_practise2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include"MyDlg.h"

// C七MFC_practise2View

IMPLEMENT_DYNCREATE(C七MFC_practise2View, CView)

BEGIN_MESSAGE_MAP(C七MFC_practise2View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// C七MFC_practise2View 构造/析构

C七MFC_practise2View::C七MFC_practise2View()
{
	// TODO: 在此处添加构造代码

}

C七MFC_practise2View::~C七MFC_practise2View()
{
}

BOOL C七MFC_practise2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C七MFC_practise2View 绘制

void C七MFC_practise2View::OnDraw(CDC* /*pDC*/)
{
	C七MFC_practise2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	MyDlg dlg;
	dlg.DoModal();
	// TODO: 在此处为本机数据添加绘制代码
}


// C七MFC_practise2View 打印

BOOL C七MFC_practise2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C七MFC_practise2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C七MFC_practise2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C七MFC_practise2View 诊断

#ifdef _DEBUG
void C七MFC_practise2View::AssertValid() const
{
	CView::AssertValid();
}

void C七MFC_practise2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C七MFC_practise2Doc* C七MFC_practise2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C七MFC_practise2Doc)));
	return (C七MFC_practise2Doc*)m_pDocument;
}
#endif //_DEBUG


// C七MFC_practise2View 消息处理程序
