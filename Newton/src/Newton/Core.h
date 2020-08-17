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

#ifdef HZ_ENABLE_ASSERTS
	#define NEWTON_ASSERT(x, ...) { if(!(x)) { NEWTON_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define NEWTON_CORE_ASSERT(x, ...) { if(!(x)) { NEWTON_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define NEWTON_ASSERT(x, ...)
	#define NEWTON_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)
