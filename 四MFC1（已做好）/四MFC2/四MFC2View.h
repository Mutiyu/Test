
// 四MFC2View.h : C四MFC2View 类的接口
//

#pragma once


class C四MFC2View : public CView
{
protected: // 仅从序列化创建
	C四MFC2View();
	DECLARE_DYNCREATE(C四MFC2View)

// 特性
public:
	C四MFC2Doc* GetDocument() const;

// 操作
public:
	int M,N,a,b;
	CRect cr;
	bool set;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~C四MFC2View();
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
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 四MFC2View.cpp 中的调试版本
inline C四MFC2Doc* C四MFC2View::GetDocument() const
   { return reinterpret_cast<C四MFC2Doc*>(m_pDocument); }
#endif

