#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Crumble {

	class CRUMBLE_API Log
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

// Core log macros
#define CR_CORE_TRACE(...)    ::Crumble::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CR_CORE_INFO(...)     ::Crumble::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CR_CORE_WARN(...)     ::Crumble::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CR_CORE_ERROR(...)    ::Crumble::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CR_CORE_CRITICAL(...) ::Crumble::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define CR_TRACE(...)         ::Crumble::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CR_INFO(...)          ::Crumble::Log::GetClientLogger()->info(__VA_ARGS__)
#define CR_WARN(...)          ::Crumble::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CR_ERROR(...)         ::Crumble::Log::GetClientLogger()->error(__VA_ARGS__)
#define CR_CRITICAL(...)      ::Crumble::Log::GetClientLogger()->critical(__VA_ARGS__)
