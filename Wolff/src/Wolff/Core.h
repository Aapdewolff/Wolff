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

#define BIT(x) (1 << x)