#include "Wolffpch.h"
#include "Application.h"

namespace Wolff {
	Application::Application()
	{
		window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		while (running)
		{
			window->OnUpdate();
		}
	}
}