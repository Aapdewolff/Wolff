#pragma once

#include "Core.h"

namespace Wolff {
	class WOLFF_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}