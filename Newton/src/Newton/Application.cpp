#include "Application.h"

#include "Newton/Events/ApplicationEvent.h"
#include "Newton/Log.h"

namespace Newton {
	
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		NEWTON_INFO(e);

		while (true);
	}
}