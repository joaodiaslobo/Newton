#pragma once

#include "Core.h"

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

