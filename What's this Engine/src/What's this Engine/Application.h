#pragma once

#include "core.h"

namespace WTE
{
	class WTE_API Application
	{
	public:
		Application();

		virtual ~Application();

		void Run();
	};
	// �ڿͻ��˴�����ʵ�� CreateApplication ����
	Application* CreateApplication();
}