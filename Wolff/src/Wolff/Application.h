#pragma once

#include "Core.h"

#include "Events/ApplicationEvent.h"

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