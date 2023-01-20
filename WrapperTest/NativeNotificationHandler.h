#pragma once

#include "pch.h"
#include "gcroot.h"
#include "NotificationHandler.h"

namespace Wrapper
{
	ref class PluginNotificationHandler;

	class NativeNotificationHandler : public NotificationHandler
	{
	public:
		NativeNotificationHandler(PluginNotificationHandler ^ pluginNotificationHandler);

	protected:
		void OnShowWpfMessageEvent() override;
		void OnHideWpfMessageEvent() override;

	private:
		gcroot<PluginNotificationHandler ^> m_pluginNotificationHandler;
	};
}
