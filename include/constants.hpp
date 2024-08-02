#pragma once
#define int_id typeid(int)
#define float_id typeid(float)
#define double_id typeid(double)

/// Speed of Light in vacuum in meters per second
#define LIGHT_SPEED 299792458

#if defined(__clang__)
#define FORCE_INLINE [[clang::always_inline]] inline

#elif defined(__GNUC__)
#define FORCE_INLINE [[gnu::always_inline]] inline

#elif defined(_MSC_VER)
#pragma warning(error : 4714)
#define FORCE_INLINE __forceinline

#else
#error Unsupported compiler
#endif
