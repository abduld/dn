//
// Created by Abdul Dakkak on 2/21/17.
//

#ifndef DN_UTILS_MPL_HPP
#define DN_UTILS_MPL_HPP

#include <type_traits>

namespace dn {
namespace mpl {
  template <size_t... Ns>
  struct mul;

  template <>
  struct mul<> {
    using value_type                  = size_t;
    static constexpr value_type value = 1;
  };

  template <size_t N, size_t... Ns>
  struct mul<N, Ns...> {
    using value_type                  = size_t;
    static constexpr value_type value = N * mul<Ns...>::value;
  };

  template <size_t... Ns>
  struct add;

  template <>
  struct add<> {
    using value_type                  = size_t;
    static constexpr value_type value = 0;
  };

  template <size_t N, size_t... Ns>
  struct add<N, Ns...> {
    using value_type                  = size_t;
    static constexpr value_type value = N + add<Ns...>::value;
  };

  template <bool cond, class T = void>
  using enable_if_t = typename std::enable_if<cond, T>::type;
}
}

#endif // DN_UTILS_MPL_HPP
