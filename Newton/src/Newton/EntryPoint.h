#pragma once

#ifdef NEWTON_PLATFORM_WINDOWS

extern Newton::Application* Newton::CreateApplication();

int main(int argc, char** argv)
{	
	auto app = Newton::CreateApplication();
	app->Run();
	delete app;
}

#endif