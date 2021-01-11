#include <Wolff.h>

class Sandbox : public Wolff::Application
{
public:
	Sandbox()
	{
		WOLFF_CLIENT_INFO("hi there");
	}

	~Sandbox()
	{

	}
};

Wolff::Application* Wolff::CreateApplication()
{
	return new Sandbox();
}