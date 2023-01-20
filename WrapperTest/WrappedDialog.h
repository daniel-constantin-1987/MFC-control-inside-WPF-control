#pragma once
#include "PluginNotificationHandler.h"
#include <afxwin.h>
#include <NativeTest.h>

namespace Wrapper
{
	public ref class WrappedDialog
	{
	public:
		WrappedDialog(System::IntPtr parentWindowHandle,
			Wrapper::PluginNotificationHandler^ pluginNotificationHandler);

		void ShowMfcText(bool show);

	private:

		HWND m_parentWindowHandle;
		CWnd* m_parentWindow;
		NativeTest* m_nativeTest;

		Wrapper::PluginNotificationHandler^ m_pluginNotificationHandler;
	};
}

