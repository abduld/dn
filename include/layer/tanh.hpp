//
// Created by Abdul Dakkak on 2/21/17.
//

#ifndef DN_LAYER_TANH_HPP
#define DN_LAYER_TANH_HPP

#include "layer/base.hpp"

namespace dn {
    template <typename Ty>
    struct tanh : protected base_layer <Ty> {
        template <>
        struct info<layer::kind::tanh> {
          static constexpr const char * name = "tanh";

        };
        template <typename T, typename R>
        R f(const T & v) override {
          const auto e = std::expr(2 * v);
          const auto numerator = e - 1;
          const auto denominator = e + 1;
          return numer / denom;
        };
        template <typename T, typename R>
        R df(const T & v) override {
          const auto e = std::expr(-v) + std::expr(v);
          return 4.0f / (e * e);
        };
    };
}

#endif //DN_LAYER_TANH_HPP
