
// Test_0318View.h : CTest_0318View ��Ľӿ�
//

#pragma once


class CTest_0318View : public CView
{
protected: // �������л�����
	CTest_0318View();
	DECLARE_DYNCREATE(CTest_0318View)

// ����
public:
	CTest_0318Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CTest_0318View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Test_0318View.cpp �еĵ��԰汾
inline CTest_0318Doc* CTest_0318View::GetDocument() const
   { return reinterpret_cast<CTest_0318Doc*>(m_pDocument); }
#endif

