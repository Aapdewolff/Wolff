#include "Wolffpch.h"
#include "Application.h"

#include "Core.h"

#include <glad/glad.h>

namespace Wolff {
	Application::Application()
	{
		window = std::unique_ptr<Window>(Window::Create());
		window->SetEventCallback(BIND_EVENT_FUNCTION(Application::OnEvent));
	}

	Application::~Application() { }

	void Application::OnEvent(Event& event)
	{
		EventDispatcher dispatcher(event);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FUNCTION(Application::OnWindowClose));

		WOLFF_CORE_TRACE("{0}", event);

		for (auto it = layerStack.end(); it != layerStack.begin(); )
		{
			(*--it)->OnEvent(event);
			if (event.handled)
				break;
		}
	}

	void Application::Run()
	{
		while (running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			for (Layer* layer : layerStack)
				layer->OnUpdate();

			window->OnUpdate();
		}
	}

	void Application::PushLayer(Layer* layer)
	{
		layerStack.PushLayer(layer);
	}

	void Application::PushOverlay(Layer* layer)
	{
		layerStack.PushOverlay(layer);
	}

	bool Application::OnWindowClose(WindowCloseEvent& event)
	{
		running = false;
		return true;
	}
}