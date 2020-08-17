#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"


namespace Newton {
	class NEWTON_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

//Core Logger Macros
#define NEWTON_CORE_TRACE(...)   ::Newton::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define NEWTON_CORE_INFO(...)    ::Newton::Log::GetCoreLogger()->info(__VA_ARGS__)
#define NEWTON_CORE_WARN(...)    ::Newton::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define NEWTON_CORE_ERROR(...)   ::Newton::Log::GetCoreLogger()->error(__VA_ARGS__)
#define NEWTON_CORE_FATAL(...)   ::Newton::Log::GetCoreLogger()->critical(__VA_ARGS__)
							     
//Client Logger Macros		     
#define NEWTON_TRACE(...)        ::Newton::Log::GetClientLogger()->trace(__VA_ARGS__)
#define NEWTON_INFO(...)         ::Newton::Log::GetClientLogger()->info(__VA_ARGS__)
#define NEWTON_WARN(...)         ::Newton::Log::GetClientLogger()->warn(__VA_ARGS__)
#define NEWTON_ERROR(...)        ::Newton::Log::GetClientLogger()->error(__VA_ARGS__)
#define NEWTON_FATAL(...)        ::Newton::Log::GetClientLogger()->critical(__VA_ARGS__)



