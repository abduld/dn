//
// Created by Abdul Dakkak on 2/21/17.
//

#ifndef DN_TENSOR_ONES_HPP
#define DN_TENSOR_ONES_HPP

#include "tensor/base.hpp"

namespace dn {

template <typename Ty, index_type... Dims>
struct ones final : public base_tensor<Ty, Dims...> {
  explicit ones() : base_tensor<Ty, Dims...>() {
    std::fill(_data, _data + flattened_length, static_cast<Ty>(1));
  }
};

template <typename Ty, index_type... Dims>
ones<Ty, Dims...> ones_like() {
  return ones<Ty, Dims...>();
}
}

#endif // DN_TENSOR_ONES_HPP
