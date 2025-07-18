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
	// 在客户端代码中实现 CreateApplication 函数
	Application* CreateApplication();
}