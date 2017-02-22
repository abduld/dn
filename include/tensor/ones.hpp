//
// Created by Abdul Dakkak on 2/21/17.
//

#ifndef DN_TENSOR_ONES_HPP
#define DN_TENSOR_ONES_HPP

#include "tensor/base.hpp"

namespace dn {

template <typename Ty, tensor_dim_t... Dims>
struct ones final : private base_tensor<Ty, Dims...> {
  ones() {
    std::fill(_data, _data + flattened_length, static_cast<Ty>(1));
  }
};

template <typename Ty, tensor_dim_t... Dims>
ones<Ty, Dims...> ones_like() {
  return ones<Ty, Dims...>();
}
}

#endif // DN_TENSOR_ONES_HPP
