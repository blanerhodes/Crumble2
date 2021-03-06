#pragma once

#include <memory>

#ifdef CR_PLATFORM_WINDOWS
#if CR_DYNAMIC_LINK
	#ifdef CR_BUILD_DLL
		#define CRUMBLE_API __declspec(dllexport)
	#else
		#define CRUMBLE_API __declspec(dllimport)
	#endif
#else
    #define CRUMBLE_API
#endif
#else
	#error Crumble only supports Windows!
#endif

#ifdef CR_DEBUG
	#define CR_ENABLE_ASSERTS
#endif

#ifdef CR_ENABLE_ASSERTS
	#define CR_ASSERT(x, ...) { if(!(x)) { CR_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define CR_CORE_ASSERT(x, ...) { if(!(x)) { CR_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define CR_ASSERT(x, ...)
	#define CR_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define CR_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

namespace Crumble {

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
