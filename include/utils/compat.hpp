//
// Created by Abdul Dakkak on 2/21/17.
//

#ifndef DN_UTILS_COMPAT_HPP
#define DN_UTILS_COMPAT_HPP

#ifdef __GNUC__
#define UNUSED __attribute__((unused))
#else // __GNUC__
#define UNUSED
#endif // __GNUC__

#if defined(__GNUC__)
#define ALWAYS_INLINE __attribute__((always_inline))
#else // defined(__GNUC__)
#define ALWAYS_INLINE __forceinline
#endif // defined(__GNUC__)

#endif //DN_UTILS_COMPAT_HPP
