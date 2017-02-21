//
// Created by Abdul Dakkak on 2/21/17.
//

#ifndef DN_RANDN_HPP
#define DN_RANDN_HPP

#include <random>

#include "tensor/base.hpp"

namespace dn {

    template <typename Ty, tensor_dim_t ...Dims>
    struct randn : private tensor_base<Ty, Dims...> {
        randn() {
          std::random_device rd;
          std::mt19937 gen(rd());
          std::uniform_real_distribution<> dis(0, 1);

          for (const auto ii : range(0, flattened_length)) {
            _data[ii] = dis(gen);
          }
        }
    };
}

#endif //DN_RANDN_HPP
