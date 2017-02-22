//
// Created by Abdul Dakkak on 2/21/17.
//

#ifndef DN_LAYER_SQUARE_HPP
#define DN_LAYER_SQUARE_HPP

#include "layer/base.hpp"

namespace dn {
template <typename Ty>
struct square : protected base_layer<Ty> {
  template <>
  struct info<layer::kind::tanh> {
    static constexpr const char* name = "square";
  };
  template <typename T, typename R>
  R f(const T& v) override {
    return v * v;
  };
  template <typename T, typename R>
  R df(const T& v) override {
    return 2 * v;
  };
};
}

#endif // DN_LAYER_SQUARE_HPP
