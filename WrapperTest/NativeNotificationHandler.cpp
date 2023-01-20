#include "pch.h"
#include "NativeNotificationHandler.h"
#include "PluginNotificationHandler.h"

namespace Wrapper
{

	NativeNotificationHandler::NativeNotificationHandler(PluginNotificationHandler^ pluginNotificationHandler)
		: m_pluginNotificationHandler(pluginNotificationHandler)
	{
	}

	void NativeNotificationHandler::OnShowWpfMessageEvent()
	{
		m_pluginNotificationHandler->OnShowWpfMessageChanged();
	}

	void NativeNotificationHandler::OnHideWpfMessageEvent()
	{
		m_pluginNotificationHandler->OnHideWpfMessageChanged();
	}
}