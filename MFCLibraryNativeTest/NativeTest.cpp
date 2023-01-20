#include "pch.h"
#include "NativeTest.h"

NativeTest::NativeTest(NotificationHandler* notificationHandler, CWnd* windowParent)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	m_notificationHandler = notificationHandler;
	m_windowParent = windowParent;

	m_dialog = new NativeTestDialog(m_notificationHandler, m_windowParent);

	if (m_dialog != NULL)
	{
		BOOL ret = m_dialog->Create(NativeTestDialog::IDD, m_windowParent);

		if (!ret)
		{
			AfxMessageBox(_T("Error creating Dialog"));
		}
	}
}

void NativeTest::ShowMfcText(bool show)
{
	m_dialog->ShowMfcText(show);
}