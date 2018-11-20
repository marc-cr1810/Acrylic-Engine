#pragma once

#ifdef AC_PLATFORM_WINDOWS
	#ifdef AC_BUILD_DLL
		#define ACRYLIC_API	__declspec(dllexport)
	#else
		#define ACRYLIC_API	__declspec(dllimport)
	#endif
#else
	#error Acrylic is only supported on Windows systems
#endif