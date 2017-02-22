//
// Created by Abdul Dakkak on 2/21/17.
//

#ifndef DN_TENSOR_RANDN_HPP
#define DN_TENSOR_RANDN_HPP

#include <random>

#include "tensor/base.hpp"

namespace dn {

template <typename Ty, index_type... Dims>
struct randn final : public base_tensor<Ty, Dims...> {
  double mu{0};
  double stddev{0};

  randn(double mu = 0.0, double stddev = 1.0)
      : base_tensor<Ty, Dims...>(), mu(mu), stddev(stddev) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> dis(mu, stddev);

    for (const auto ii : range(0, this->flattened_length)) {
      this->_data[ii] = dis(gen);
    }
  }
};
}

#endif // DN_TENSOR_RANDN_HPP
