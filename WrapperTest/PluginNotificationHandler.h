#pragma once

#include "NativeNotificationHandler.h"

namespace Wrapper
{
	public ref class PluginNotificationHandler
	{
	public:
		PluginNotificationHandler();

		event System::EventHandler^ ShowWpfMessageChanged;

		event System::EventHandler^ HideWpfMessageChanged;

	internal:

		void OnShowWpfMessageChanged();

		void OnHideWpfMessageChanged();

		NativeNotificationHandler * GetNative();

	private:

		NativeNotificationHandler * m_native;
	};
}

