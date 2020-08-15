#pragma once

#ifdef NEWTON_PLATFORM_WINDOWS
	#ifdef NEWTON_BUILD_DLL
		#define NEWTON_API _declspec(dllexport)
	#else
		#define NEWTON_API _declspec(dllimport)
	#endif
#else
	#error Windows is required to run this application!
#endif
