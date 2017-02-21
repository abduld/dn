//
// Created by Abdul Dakkak on 2/21/17.
//

#ifndef DN_ZEROS_HPP
#define DN_ZEROS_HPP

#include "tensor/base.hpp"

namespace dn {

    template <typename Ty, tensor_dim_t ...Dims>
    struct zeros : private tensor_base<Ty, Dims...> {
      zeros() {
        memset(_data, 0, byte_count);
      }
    };


    template <typename Ty, tensor_dim_t ...Dims>
    zeros<Ty, Dims...> zeros_like() {
      return zeros<Ty, Dims...>();
    }
}

#endif //DN_ZEROS_HPP
