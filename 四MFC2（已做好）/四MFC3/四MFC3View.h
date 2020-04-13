
// 四MFC3View.h : C四MFC3View 类的接口
//

#pragma once


class C四MFC3View : public CView
{
protected: // 仅从序列化创建
	C四MFC3View();
	DECLARE_DYNCREATE(C四MFC3View)

// 特性
public:
	C四MFC3Doc* GetDocument() const;

// 操作
public:
	CRect cr;
	CPoint c;
	int flag;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//virtual BOOL OnPreTranslateMessage(MSG *pMsg);
// 实现
public:
	virtual ~C四MFC3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // 四MFC3View.cpp 中的调试版本
inline C四MFC3Doc* C四MFC3View::GetDocument() const
   { return reinterpret_cast<C四MFC3Doc*>(m_pDocument); }
#endif

