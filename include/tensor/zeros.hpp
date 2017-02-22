//
// Created by Abdul Dakkak on 2/21/17.
//

#ifndef DN_TENSOR_ZEROS_HPP
#define DN_TENSOR_ZEROS_HPP

#include "tensor/base.hpp"

namespace dn {

    template <typename Ty, tensor_dim_t ...Dims>
    struct zeros final : private base_tensor<Ty, Dims...> {
      zeros() {
        std::fill(_data, _data + flattened_length, static_cast<Ty>(0));
      }
    };


    template <typename Ty, tensor_dim_t ...Dims>
    zeros<Ty, Dims...> zeros_like() {
      return zeros<Ty, Dims...>();
    }
}

#endif //DN_TENSOR_ZEROS_HPP
