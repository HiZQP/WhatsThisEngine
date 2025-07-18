#pragma once

#include "core.h"

namespace WhatsThisEngine
{
	class WTE_API Application
	{
	public:
		Application();

		virtual ~Application();

		void Run();
	};
}