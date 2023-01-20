#pragma once
#include <afxwin.h>
#include "NotificationHandler.h"
#include "resource.h"

class NativeTestDialog : public CDialog
{
public:
	NativeTestDialog(NotificationHandler* notificationHandler, CWnd* pParent);

	BOOL Create(UINT nIDTemplate, CWnd* pParentWnd);

	void ShowMfcText(bool show);

	enum { IDD = IDD_DIALOG_TEST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);

protected:
	BOOL m_bIsShowWpfMessageChecked;
	NotificationHandler* m_notificationHandler;

	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedCheckMessage();
};

