
// 二MFC3View.h : C二MFC3View 类的接口
//

#pragma once


class C二MFC3View : public CView
{
protected: // 仅从序列化创建
	C二MFC3View();
	DECLARE_DYNCREATE(C二MFC3View)

// 特性
public:
	C二MFC3Doc* GetDocument() const;

// 操作
public:

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
	virtual ~C二MFC3View();
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
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 二MFC3View.cpp 中的调试版本
inline C二MFC3Doc* C二MFC3View::GetDocument() const
   { return reinterpret_cast<C二MFC3Doc*>(m_pDocument); }
#endif

