
// 三MFC1View.h : C三MFC1View 类的接口
//

#pragma once


class C三MFC1View : public CView
{
protected: // 仅从序列化创建
	C三MFC1View();
	DECLARE_DYNCREATE(C三MFC1View)

// 特性
public:
	C三MFC1Doc* GetDocument() const;

// 操作
public:
	CString cn;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~C三MFC1View();
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
};

#ifndef _DEBUG  // 三MFC1View.cpp 中的调试版本
inline C三MFC1Doc* C三MFC1View::GetDocument() const
   { return reinterpret_cast<C三MFC1Doc*>(m_pDocument); }
#endif

