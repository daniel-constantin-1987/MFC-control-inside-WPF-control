#pragma once
#include "NotificationHandler.h"
#include "NativeTestDialog.h"
class __declspec(dllexport) NativeTest
{
public:
	NativeTest(NotificationHandler * notificationHandler, CWnd* windowParent);

	void ShowMfcText(bool show);

private:
	CWnd* m_windowParent;
	NativeTestDialog* m_dialog;
	NotificationHandler* m_notificationHandler;
};

