#include <Wolff.h>

class MyLayer : public Wolff::Layer
{
public:
	MyLayer() : Layer("MyLayer")
	{

	}

	void OnUpdate() override
	{

	}

	void OnEvent(Wolff::Event& event) override
	{
		WOLFF_CLIENT_TRACE("{0}", event);
	}
};

class Sandbox : public Wolff::Application
{
public:
	Sandbox()
	{
		PushLayer(new MyLayer());
	}

	~Sandbox() { }
};

Wolff::Application* Wolff::CreateApplication()
{
	return new Sandbox();
}