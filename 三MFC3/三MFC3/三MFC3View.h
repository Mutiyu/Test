
// 三MFC3View.h : C三MFC3View 类的接口
//

#pragma once


class C三MFC3View : public CView
{
protected: // 仅从序列化创建
	C三MFC3View();
	DECLARE_DYNCREATE(C三MFC3View)

// 特性
public:
	C三MFC3Doc* GetDocument() const;

// 操作
public:
	int a;
	int b;
	int c;
	CString s1, s2, s3;
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
	virtual ~C三MFC3View();
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

#ifndef _DEBUG  // 三MFC3View.cpp 中的调试版本
inline C三MFC3Doc* C三MFC3View::GetDocument() const
   { return reinterpret_cast<C三MFC3Doc*>(m_pDocument); }
#endif

