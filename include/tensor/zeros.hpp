//
// Created by Abdul Dakkak on 2/21/17.
//

#ifndef DN_TENSOR_ZEROS_HPP
#define DN_TENSOR_ZEROS_HPP

#include "tensor/base.hpp"

namespace dn {

template <typename Ty, index_type... Dims>
struct zeros : public base_tensor<Ty, Dims...> {
  zeros() : base_tensor<Ty, Dims...>() {
    std::fill(this->_data, this->_data + this->flattened_length,
              static_cast<Ty>(0));
  }
};

template <typename Ty, index_type... Dims>
zeros<Ty, Dims...> zeros_like() {
  return zeros<Ty, Dims...>();
}
}

#endif // DN_TENSOR_ZEROS_HPP
