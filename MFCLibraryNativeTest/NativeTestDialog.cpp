#include "pch.h"
#include "NativeTestDialog.h"

NativeTestDialog::NativeTestDialog(NotificationHandler* notificationHandler, CWnd* pParent) : CDialog(IDD_DIALOG_TEST, pParent)
{
    m_bIsShowWpfMessageChecked = FALSE;
    m_notificationHandler = notificationHandler;
}

BOOL NativeTestDialog::Create(UINT nIDTemplate, CWnd* pParentWnd)
{
    return CDialog::Create(nIDTemplate, pParentWnd);
}

void NativeTestDialog::DoDataExchange(CDataExchange* pDX)
{
    DDX_Check(pDX, IDC_CHECK_MESSAGE, m_bIsShowWpfMessageChecked);

    CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(NativeTestDialog, CDialog)
    ON_BN_CLICKED(IDC_CHECK_MESSAGE, &NativeTestDialog::OnBnClickedCheckMessage)
END_MESSAGE_MAP()


void NativeTestDialog::OnBnClickedCheckMessage()
{
	UpdateData(TRUE);

	if (m_bIsShowWpfMessageChecked)
	{
		m_notificationHandler->OnShowWpfMessageEvent();
	}
	else
	{
		m_notificationHandler->OnHideWpfMessageEvent();
	}
}

void NativeTestDialog::ShowMfcText(bool show)
{
	CWnd* textControl = GetDlgItem(IDC_STATIC);

	textControl->ShowWindow(show ? SW_SHOW : SW_HIDE);
}
