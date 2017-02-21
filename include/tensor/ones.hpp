//
// Created by Abdul Dakkak on 2/21/17.
//

#ifndef DN_ONES_HPP
#define DN_ONES_HPP

#include "tensor/base.hpp"

namespace dn {

    template <typename Ty, tensor_dim_t ...Dims>
    struct ones : private tensor_base<Ty, Dims...> {
        ones() {
          memset(_data, 0, byte_count);
        }
    };


    template <typename Ty, tensor_dim_t ...Dims>
    ones<Ty, Dims...> ones_like() {
      return ones<Ty, Dims...>();
    }
}

#endif //DN_ONES_HPP
