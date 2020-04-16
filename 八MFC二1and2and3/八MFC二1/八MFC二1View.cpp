
// 八MFC二1View.cpp : C八MFC二1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "八MFC二1.h"
#endif

#include "八MFC二1Doc.h"
#include "八MFC二1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include"MyDlg.h"

// C八MFC二1View

IMPLEMENT_DYNCREATE(C八MFC二1View, CView)

BEGIN_MESSAGE_MAP(C八MFC二1View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_popDlg, &C八MFC二1View::Onpopdlg)
END_MESSAGE_MAP()

// C八MFC二1View 构造/析构

C八MFC二1View::C八MFC二1View()
{
	// TODO: 在此处添加构造代码
	filename = "yu";
}

C八MFC二1View::~C八MFC二1View()
{
}

BOOL C八MFC二1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C八MFC二1View 绘制

void C八MFC二1View::OnDraw(CDC* /*pDC*/)
{
	C八MFC二1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C八MFC二1View 打印

BOOL C八MFC二1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C八MFC二1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C八MFC二1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C八MFC二1View 诊断

#ifdef _DEBUG
void C八MFC二1View::AssertValid() const
{
	CView::AssertValid();
}

void C八MFC二1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C八MFC二1Doc* C八MFC二1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C八MFC二1Doc)));
	return (C八MFC二1Doc*)m_pDocument;
}
#endif //_DEBUG


// C八MFC二1View 消息处理程序


void C八MFC二1View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	if (r == IDOK)
	{
		 filename = cfd.GetFileName();
		GetDC()->TextOutW(300, 300, filename);
	}


	CView::OnLButtonDblClk(nFlags, point);
}


void C八MFC二1View::Onpopdlg()
{
	// TODO: 在此添加命令处理程序代码

	MyDlg *pd = new MyDlg;
	UpdateData(true);
	pd->s = filename;
	pd->set = true;
	pd->Create(IDD_DIALOG1);
	pd->ShowWindow(1);
	UpdateData(false);


}
