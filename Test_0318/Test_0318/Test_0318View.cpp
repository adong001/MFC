
// Test_0318View.cpp : CTest_0318View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Test_0318.h"
#endif

#include "Test_0318Doc.h"
#include "Test_0318View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTest_0318View

IMPLEMENT_DYNCREATE(CTest_0318View, CView)

BEGIN_MESSAGE_MAP(CTest_0318View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CTest_0318View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CTest_0318View ����/����

CTest_0318View::CTest_0318View()
{
	// TODO:  �ڴ˴���ӹ������

}

CTest_0318View::~CTest_0318View()
{
}

BOOL CTest_0318View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CTest_0318View ����

void CTest_0318View::OnDraw(CDC* /*pDC*/)
{
	CTest_0318Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CTest_0318View ��ӡ


void CTest_0318View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CTest_0318View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CTest_0318View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CTest_0318View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}

void CTest_0318View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CTest_0318View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CTest_0318View ���

#ifdef _DEBUG
void CTest_0318View::AssertValid() const
{
	CView::AssertValid();
}

void CTest_0318View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTest_0318Doc* CTest_0318View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTest_0318Doc)));
	return (CTest_0318Doc*)m_pDocument;
}
#endif //_DEBUG


// CTest_0318View ��Ϣ�������
