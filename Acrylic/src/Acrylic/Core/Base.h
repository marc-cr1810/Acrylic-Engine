#pragma once

#include <memory>

#include "Acrylic/Core/PlatformDetection.h"

#ifdef AC_DEBUG
	#if defined(AC_PLATFORM_WINDOWS)
		#define AC_DEBUGBREAK() __debugbreak()
	#elif defined(AC_PLATFORM_LINUX)
		#include <signal.h>
		#define AC_DEBUGBREAK() raise(SIGTRAP)
	#else
		#error "Platform doesn't support debugbreak yet!"
	#endif
	#define AC_ENABLE_ASSERTS
#else
	#define AC_DEBUGBREAK()
#endif

/// TODO: Make this macro able to take in no arguments except condition
#ifdef AC_ENABLE_ASSERTS
	#define AC_ASSERT(x, ...) { if(!(x)) { AC_ERROR("Assertion Failed: {0}", __VA_ARGS__); AC_DEBUGBREAK(); } }
	#define AC_CORE_ASSERT(x, ...) { if(!(x)) { AC_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); AC_DEBUGBREAK(); } }
#else
	#define AC_ASSERT(x, ...)
	#define AC_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define AC_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

namespace Acrylic
{
	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}
}