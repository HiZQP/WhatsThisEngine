#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace WTE
{
	class WTE_API Log
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

// 核心日志宏定义
#define WTE_CORE_TRACE(...)    ::WTE::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define WTE_CORE_INFO(...)     ::WTE::Log::GetCoreLogger()->info(__VA_ARGS__)
#define WTE_CORE_WARN(...)     ::WTE::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define WTE_CORE_ERROR(...)    ::WTE::Log::GetCoreLogger()->error(__VA_ARGS__)
#define WTE_CORE_FATAL(...)    ::WTE::Log::GetCoreLogger()->critical(__VA_ARGS__)

// 客户端日志宏定义
#define WTE_TRACE(...)         ::WTE::Log::GetClientLogger()->trace(__VA_ARGS__)
#define WTE_INFO(...)          ::WTE::Log::GetClientLogger()->info(__VA_ARGS__)
#define WTE_WARN(...)          ::WTE::Log::GetClientLogger()->warn(__VA_ARGS__)
#define WTE_ERROR(...)         ::WTE::Log::GetClientLogger()->error(__VA_ARGS__)
#define WTE_FATAL(...)         ::WTE::Log::GetClientLogger()->critical(__VA_ARGS__)