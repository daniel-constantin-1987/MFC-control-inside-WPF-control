#include "pch.h"
#include "WrappedDialog.h"

namespace Wrapper
{
	WrappedDialog::WrappedDialog(System::IntPtr parentWindowHandle,
		Wrapper::PluginNotificationHandler^ pluginNotificationHandler)
	{
		m_pluginNotificationHandler = pluginNotificationHandler;
		m_parentWindowHandle = (HWND)parentWindowHandle.ToPointer();
		m_parentWindow = CWnd::FromHandle(m_parentWindowHandle);

		m_nativeTest = new NativeTest(m_pluginNotificationHandler->GetNative(), m_parentWindow);
	}

	void WrappedDialog::ShowMfcText(bool show)
	{
		m_nativeTest->ShowMfcText(show);
	}
}