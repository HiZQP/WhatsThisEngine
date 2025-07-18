#pragma once

#ifdef WTE_PLATFORM_WINDOWS
	#ifdef WTE_BUILD_DLL
		#define WTE_API __declspec(dllexport)
	#else
		#define WTE_API __declspec(dllimport)
	#endif
#else
	#error WTE only supports Windows!
#endif