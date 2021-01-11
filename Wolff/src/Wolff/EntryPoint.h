#pragma once

#ifdef WOLFF_PLATFORM_WINDOWS

#include "Application.h"
#include "Log.h"

extern Wolff::Application* Wolff::CreateApplication();

int main(int argc, char** argv)
{
	Wolff::Log::Init();

	Wolff::Application* app = Wolff::CreateApplication();
	app->Run();
	delete app;

	return 0;
}
#endif