
// ��MFC3View.cpp : C��MFC3View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��MFC3.h"
#endif

#include "��MFC3Doc.h"
#include "��MFC3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��MFC3View

IMPLEMENT_DYNCREATE(C��MFC3View, CView)

BEGIN_MESSAGE_MAP(C��MFC3View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_KEYDOWN()
	ON_WM_CHAR()
END_MESSAGE_MAP()

// C��MFC3View ����/����

C��MFC3View::C��MFC3View()
{
	// TODO: �ڴ˴���ӹ������
	cr.left = 300; cr.top =360;
	cr.right = 200; cr.bottom =250;
}

C��MFC3View::~C��MFC3View()
{
}

BOOL C��MFC3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C��MFC3View ����

void C��MFC3View::OnDraw(CDC* pDC)
{
	C��MFC3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(cr);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C��MFC3View ��ӡ

BOOL C��MFC3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C��MFC3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C��MFC3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C��MFC3View ���

#ifdef _DEBUG
void C��MFC3View::AssertValid() const
{
	CView::AssertValid();
}

void C��MFC3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C��MFC3Doc* C��MFC3View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��MFC3Doc)));
	return (C��MFC3Doc*)m_pDocument;
}
#endif //_DEBUG


// C��MFC3View ��Ϣ�������


void C��MFC3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	cr.left = 300; cr.top = 360;
	cr.right = 200; cr.bottom = 250;
	InvalidateRect(NULL, TRUE);
	CView::OnLButtonDown(nFlags, point);
}


void C��MFC3View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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


void C��MFC3View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
