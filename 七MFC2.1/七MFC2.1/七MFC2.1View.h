
// 七MFC2.1View.h : C七MFC21View 类的接口
//

#pragma once


class C七MFC21View : public CView
{
protected: // 仅从序列化创建
	C七MFC21View();
	DECLARE_DYNCREATE(C七MFC21View)

// 特性
public:
	C七MFC21Doc* GetDocument() const;

// 操作
public:
	CRect cr;
	bool set;
	CPoint cp;
	int x1, x2, y1, y2;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~C七MFC21View();
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
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 七MFC2.1View.cpp 中的调试版本
inline C七MFC21Doc* C七MFC21View::GetDocument() const
   { return reinterpret_cast<C七MFC21Doc*>(m_pDocument); }
#endif

