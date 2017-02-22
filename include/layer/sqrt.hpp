//
// Created by Abdul Dakkak on 2/21/17.
//

#ifndef DN_LAYER_SQRT_HPP
#define DN_LAYER_SQRT_HPP

#include "layer/base.hpp"

namespace dn {
template <typename Ty>
struct sqrt : protected base_layer<Ty> {
  template <>
  struct info<layer::kind::tanh> {
    static constexpr const char* name = "tanh";
  };
  template <typename T, typename R>
  R f(const T& v) override {
    return std::sqrt(v);
  };
  template <typename T, typename R>
  R df(const T& v) override {
    const auto numerator   = 1.0f;
    const auto denominator = 2 * std::sqrt(v);
    return numerator / denominator;
  };
};
}

#endif // DN_LAYER_SQRT_HPP
