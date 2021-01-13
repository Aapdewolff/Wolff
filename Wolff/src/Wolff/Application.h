#pragma once

#include "Core.h"

#include "Events/ApplicationEvent.h"
#include "Window.h"
#include "LayerStack.h"

namespace Wolff {
	class WOLFF_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& event);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	private:
		bool OnWindowClose(WindowCloseEvent& event);

		std::unique_ptr<Window> window;
		bool running = true;

		LayerStack layerStack;
	};

	Application* CreateApplication();
}