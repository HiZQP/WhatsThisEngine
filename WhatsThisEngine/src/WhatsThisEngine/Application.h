#pragma once

#include "Core.h"

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