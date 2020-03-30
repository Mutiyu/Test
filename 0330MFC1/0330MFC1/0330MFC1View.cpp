
// 0330MFC1View.cpp : CMy0330MFC1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0330MFC1.h"
#endif

#include "0330MFC1Doc.h"
#include "0330MFC1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0330MFC1View

IMPLEMENT_DYNCREATE(CMy0330MFC1View, CView)

BEGIN_MESSAGE_MAP(CMy0330MFC1View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_FILE_OPEN, &CMy0330MFC1View::OnFileOpen)
END_MESSAGE_MAP()

// CMy0330MFC1View 构造/析构

CMy0330MFC1View::CMy0330MFC1View()
{
	// TODO: 在此处添加构造代码

}

CMy0330MFC1View::~CMy0330MFC1View()
{
}

BOOL CMy0330MFC1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy0330MFC1View 绘制

void CMy0330MFC1View::OnDraw(CDC* /*pDC*/)
{
	CMy0330MFC1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy0330MFC1View 打印

BOOL CMy0330MFC1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy0330MFC1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy0330MFC1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy0330MFC1View 诊断

#ifdef _DEBUG
void CMy0330MFC1View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0330MFC1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0330MFC1Doc* CMy0330MFC1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0330MFC1Doc)));
	return (CMy0330MFC1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0330MFC1View 消息处理程序


void CMy0330MFC1View::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	CClientDC dc(this);
	CRect cr;
	GetClientRect(&cr);
	if (r == IDOK)
	{
		CString filename = cfd.GetPathName();
		dc.TextOutW(0, 0, filename);
		CImage img;
		img.Load(filename);
		double rect_ratio = 1.0*cr.Width() / cr.Height();
		double img_ratio = 1.0*img.GetWidth() / img.GetHeight();
		double  w, h, sx, sy;
		{
		
			if (rect_ratio > img_ratio)
			{
				h = cr.Height()*1.0;
				w = img_ratio*h;
				sx = (cr.Width() - w) / 2;
				sy = 0;
			}
			else
			{
				w = cr.Width()*1.0;
				h = w / img_ratio;
				sx = 0;
				sy = (cr.Height() - h) / 2;
			}
		}
		img.Draw(dc.m_hDC, sx, sy, w,h);
	}
}
