
// 八MFC一2View.cpp : C八MFC一2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "八MFC一2.h"
#endif

#include "八MFC一2Doc.h"
#include "八MFC一2View.h"
#include"MyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C八MFC一2View

IMPLEMENT_DYNCREATE(C八MFC一2View, CView)

BEGIN_MESSAGE_MAP(C八MFC一2View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_popDialog, &C八MFC一2View::Onpopdialog)
END_MESSAGE_MAP()

// C八MFC一2View 构造/析构

C八MFC一2View::C八MFC一2View()
{
	// TODO: 在此处添加构造代码

}

C八MFC一2View::~C八MFC一2View()
{
}

BOOL C八MFC一2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C八MFC一2View 绘制

void C八MFC一2View::OnDraw(CDC* /*pDC*/)
{
	C八MFC一2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	

	// TODO: 在此处为本机数据添加绘制代码
}


// C八MFC一2View 打印

BOOL C八MFC一2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C八MFC一2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C八MFC一2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C八MFC一2View 诊断

#ifdef _DEBUG
void C八MFC一2View::AssertValid() const
{
	CView::AssertValid();
}

void C八MFC一2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C八MFC一2Doc* C八MFC一2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C八MFC一2Doc)));
	return (C八MFC一2Doc*)m_pDocument;
}
#endif //_DEBUG


// C八MFC一2View 消息处理程序


void C八MFC一2View::Onpopdialog()
{
	// TODO: 在此添加命令处理程序代码
	MyDlg *pd = new MyDlg;
		pd->Create(IDD_DIALOG1);
		pd->ShowWindow(1);
}
