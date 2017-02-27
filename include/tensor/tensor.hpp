//
// Created by Abdul Dakkak on 2/21/17.
//

#ifndef DN_TENSOR_HPP
#define DN_TENSOR_HPP

#include "base.hpp"

//#include "ones.hpp"
//#include "rand.hpp"
//#include "randn.hpp"
#include "zeros.hpp"

namespace dn {
template <typename Ty, index_type... Dims>
struct tensor final : public base_tensor<Ty, Dims...> {
  using base_tensor<Ty, Dims...>::base_tensor;
};
}

#endif // DN_TENSOR_HPP
