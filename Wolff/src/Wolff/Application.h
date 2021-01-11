#pragma once

#include "Core.h"

#include "Events/ApplicationEvent.h"
#include "Window.h"

namespace Wolff {
	class WOLFF_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	private:
		std::unique_ptr<Window> window;
		bool running = true;
	};

	Application* CreateApplication();
}