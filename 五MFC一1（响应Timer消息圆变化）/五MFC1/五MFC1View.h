
// 五MFC1View.h : C五MFC1View 类的接口
//

#pragma once


class C五MFC1View : public CView
{
protected: // 仅从序列化创建
	C五MFC1View();
	DECLARE_DYNCREATE(C五MFC1View)

// 特性
public:
	C五MFC1Doc* GetDocument() const;

// 操作
public:
	CRect cr;
	CPoint cp;
	bool set;
	int t;
	CBrush cbrush;
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
	virtual ~C五MFC1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnShowcircle();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // 五MFC1View.cpp 中的调试版本
inline C五MFC1Doc* C五MFC1View::GetDocument() const
   { return reinterpret_cast<C五MFC1Doc*>(m_pDocument); }
#endif

