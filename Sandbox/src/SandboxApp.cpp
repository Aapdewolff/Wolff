#include <Wolff.h>

class Sandbox : public Wolff::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Wolff::Application* Wolff::CreateApplication()
{
	return new Sandbox();
}