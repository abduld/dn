//
// Created by Abdul Dakkak on 2/21/17.
//

#ifndef DN_LAYER_BASE_HPP
#define DN_LAYER_BASE_HPP

#include "layer/info.hpp"

namespace dn {
    struct base_layer {
      static const info info{};
        template <typename T, typename R>
          R f(const T & v) override ;
        template <typename T, typename R>
        R df(const T & v) override ;
    };
}

#endif //DN_LAYER_BASE_HPP
