
// 五MFC二1View.h : C五MFC二1View 类的接口
//

#pragma once


class C五MFC二1View : public CView
{
protected: // 仅从序列化创建
	C五MFC二1View();
	DECLARE_DYNCREATE(C五MFC二1View)

// 特性
public:
	C五MFC二1Doc* GetDocument() const;

// 操作
public:
	CBitmap cb;
	int c_Width;
	int c_Height;
	bool set1, set2, set3;
	CPoint d;
	CPoint u;
	CRect cr;

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
	virtual ~C五MFC二1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnShowmyname();
	afx_msg void OnShowline();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRectangle();
	afx_msg void Oncircle();
};

#ifndef _DEBUG  // 五MFC二1View.cpp 中的调试版本
inline C五MFC二1Doc* C五MFC二1View::GetDocument() const
   { return reinterpret_cast<C五MFC二1Doc*>(m_pDocument); }
#endif

