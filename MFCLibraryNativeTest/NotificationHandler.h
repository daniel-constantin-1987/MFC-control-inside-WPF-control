#pragma once

class __declspec(dllexport) NotificationHandler
{
public:
	NotificationHandler();

	virtual void OnShowWpfMessageEvent();
	virtual void OnHideWpfMessageEvent();
};

