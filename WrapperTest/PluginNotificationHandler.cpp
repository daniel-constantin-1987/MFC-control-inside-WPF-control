#include "pch.h"
#include "PluginNotificationHandler.h"
#include <exception>

namespace Wrapper
{
	PluginNotificationHandler::PluginNotificationHandler()
		try : m_native(new NativeNotificationHandler(this))
	{
	}
	catch (...)
	{
		throw gcnew System::Exception();
	}

	void PluginNotificationHandler::OnShowWpfMessageChanged()
	{
		try
		{
			ShowWpfMessageChanged(this, System::EventArgs::Empty);
		}
		catch (const std::exception&)
		{
			throw gcnew System::Exception();
		}
	}

	void PluginNotificationHandler::OnHideWpfMessageChanged()
	{
		try
		{
			HideWpfMessageChanged(this, System::EventArgs::Empty);
		}
		catch (const std::exception&)
		{
			throw gcnew System::Exception();
		}
	}

	NativeNotificationHandler * PluginNotificationHandler::GetNative()
	{
		return m_native;
	}
}