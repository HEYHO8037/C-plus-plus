#include <afxwin.h>

class CHelloApp : public CWinApp
{
public:
	virtual BOOL InitInstance();
};

class CMainFrame : public CFrameWnd
{
public:
	CMainFrame();

protected:
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	DECLARE_MESSAGE_MAP();
};

CHelloApp theApp;

BOOL CHelloApp::InitInstance()
{
	m_pMainWnd = new CMainFrame;
	m_pMainWnd->ShowWindow(m_nCmdShow);
	return TRUE;
}

CMainFrame::CMainFrame()
{
	Create(NULL, _T("HelloMFC"));
}

void CMainFrame::OnPaint()
{
	CPaintDC dc(this);
	const TCHAR *msg = _T("Hello, MFC");
	dc.TextOutW(100, 100, msg, lstrlen(msg));
}

void CMainFrame::OnLButtonDown(UINT nFlags, CPoint point)
{
	//AfxMessageBox(_T("마우스 클릭"));
	/*TRACE(_T("응용 프로그램 객체 주소 : %p = %p\n"), AfxGetApp(), &theApp);
	TRACE(_T("메인 윈도우 객체 주소 : %p = %p\n"), AfxGetMainWnd(), this);
	TRACE(_T("응용 프로그램 이름 : %s\n"), AfxGetAppName());*/

	TRACE(_T("인스턴스 핸들 : %p"), AfxGetInstanceHandle());
}

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()