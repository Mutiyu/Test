
// 0302MFC4View.h : CMy0302MFC4View 类的接口
//

#pragma once


class CMy0302MFC4View : public CView
{
protected: // 仅从序列化创建
	CMy0302MFC4View();
	DECLARE_DYNCREATE(CMy0302MFC4View)

// 特性
public:
	CMy0302MFC4Doc* GetDocument() const;

// 操作
public:
	CBrush cb;
	CRgn rgn;
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
	virtual ~CMy0302MFC4View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 0302MFC4View.cpp 中的调试版本
inline CMy0302MFC4Doc* CMy0302MFC4View::GetDocument() const
   { return reinterpret_cast<CMy0302MFC4Doc*>(m_pDocument); }
#endif

