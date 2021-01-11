#pragma once

#ifdef WOLFF_PLATFORM_WINDOWS
#ifdef WOLFF_BUILD_DLL
#define HAZEL_API __declspec(dllexport)
#else
#define HAZEL_API __declspec(dllimport)
#endif
#else
#error Platform not supported!
#endif