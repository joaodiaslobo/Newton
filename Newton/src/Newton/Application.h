#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Newton {

	class NEWTON_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//Defined in the client
	Application* CreateApplication();
}

