#pragma once

#ifdef WOLFF_PLATFORM_WINDOWS
#ifdef WOLFF_BUILD_DLL
#define WOLFF_API __declspec(dllexport)
#else
#define WOLFF_API __declspec(dllimport)
#endif
#else
#error Platform not supported!
#endif

#ifdef WOLFF_ENABLE_ASSERTS
#define WOLFF_CLIENT_ASSERT(x, ...) { if(!(x)) { WOLFF_CLIENT_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define WOLFF_CORE_ASSERT(x, ...) { if(!(x)) { WOLFF_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define WOLFF_ASSERT(x, ...)
#define WOLFF_CORE_ASSERT(x, ...)
#endif


#define BIT(x) (1 << x)