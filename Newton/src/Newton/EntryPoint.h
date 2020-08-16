#pragma once

#ifdef NEWTON_PLATFORM_WINDOWS

extern Newton::Application* Newton::CreateApplication();

int main(int argc, char** argv)
{	
	Newton::Log::Init();
	NEWTON_CORE_INFO("Log initialized.");
	NEWTON_INFO("Log initialized.");

	auto app = Newton::CreateApplication();
	app->Run();
	delete app;
}

#endif