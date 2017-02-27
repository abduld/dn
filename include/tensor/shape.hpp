//
// Created by Abdul Dakkak on 2/22/17.
//

#ifndef DN_TENSOR_SHAPE_HPP
#define DN_TENSOR_SHAPE_HPP

#include "tensor/detail.hpp"
#include "utils/utils.hpp"
#include <array>

namespace dn {
using index_type = size_t;
template <index_type... Dims>
struct shape : public non_copyable {

  static constexpr index_type rank = sizeof...(Dims);
  static constexpr auto dims       = std::array<index_type, rank>{Dims...};
  static constexpr size_t flattened_length = mpl::mul<Dims...>::value;
};
}

#endif // DN_TENSOR_SHAPE_HPP
