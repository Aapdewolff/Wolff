#pragma once

#include <memory.h>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Wolff {
	class WOLFF_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr < spdlog::logger>& GetCoreLogger() { return coreLogger; }
		inline static std::shared_ptr < spdlog::logger>& GetClientLogger() { return clientLogger; }
	private:
		static std::shared_ptr < spdlog::logger> coreLogger;
		static std::shared_ptr < spdlog::logger> clientLogger;
	};
}

#define WOLFF_CORE_FATAL(...)   ::Wolff::Log::GetCoreLogger()->fatal(__VA_ARGS__)
#define WOLFF_CORE_ERROR(...)   ::Wolff::Log::GetCoreLogger()->error(__VA_ARGS__)
#define WOLFF_CORE_WARN(...)    ::Wolff::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define WOLFF_CORE_INFO(...)    ::Wolff::Log::GetCoreLogger()->info(__VA_ARGS__)
#define WOLFF_CORE_TRACE(...)   ::Wolff::Log::GetCoreLogger()->trace(__VA_ARGS__)

#define WOLFF_CLIENT_FATAL(...)   ::Wolff::Log::GetClientLogger()->fatal(__VA_ARGS__)
#define WOLFF_CLIENT_ERROR(...)   ::Wolff::Log::GetClientLogger()->error(__VA_ARGS__)
#define WOLFF_CLIENT_WARN(...)    ::Wolff::Log::GetClientLogger()->warn(__VA_ARGS__)
#define WOLFF_CLIENT_INFO(...)    ::Wolff::Log::GetClientLogger()->info(__VA_ARGS__)
#define WOLFF_CLIENT_TRACE(...)   ::Wolff::Log::GetClientLogger()->trace(__VA_ARGS__)