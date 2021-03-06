#pragma once

#include "Wolff/Window.h"

#include <GLFW/glfw3.h>

namespace Wolff {
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline unsigned int GetWidth() const override { return data.width; }
		inline unsigned int GetHeight() const override { return data.height; }

		// Window attributes
		inline void SetEventCallback(const EventCallbackFunction& callback) override { data.eventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;
	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();
	private:
		GLFWwindow* window;

		struct WindowData
		{
			std::string title;
			unsigned int width, height;
			bool vSync;

			EventCallbackFunction eventCallback;
		};

		WindowData data;
	};
}