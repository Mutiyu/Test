
// 七MFC_practise1View.h : C七MFC_practise1View 类的接口
//

#pragma once


class C七MFC_practise1View : public CView
{
protected: // 仅从序列化创建
	C七MFC_practise1View();
	DECLARE_DYNCREATE(C七MFC_practise1View)

// 特性
public:
	C七MFC_practise1Doc* GetDocument() const;

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
	virtual ~C七MFC_practise1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClose();
};

#ifndef _DEBUG  // 七MFC_practise1View.cpp 中的调试版本
inline C七MFC_practise1Doc* C七MFC_practise1View::GetDocument() const
   { return reinterpret_cast<C七MFC_practise1Doc*>(m_pDocument); }
#endif

