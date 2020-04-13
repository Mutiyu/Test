
// 八MFC一3View.h : C八MFC一3View 类的接口
//

#pragma once


class C八MFC一3View : public CView
{
protected: // 仅从序列化创建
	C八MFC一3View();
	DECLARE_DYNCREATE(C八MFC一3View)

// 特性
public:
	C八MFC一3Doc* GetDocument() const;

// 操作
public:
	CRect cr;
	CRect client;
	bool set,set1;
	int t;
	
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
	virtual ~C八MFC一3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 八MFC一3View.cpp 中的调试版本
inline C八MFC一3Doc* C八MFC一3View::GetDocument() const
   { return reinterpret_cast<C八MFC一3Doc*>(m_pDocument); }
#endif

