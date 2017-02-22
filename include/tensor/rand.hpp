//
// Created by Abdul Dakkak on 2/22/17.
//

#ifndef DN_TENSOR_RAND_HPP
#define DN_TENSOR_RAND_HPP

#include <random>

#include "tensor/base.hpp"

namespace dn {

    template <typename Ty, tensor_dim_t ...Dims>
    struct randi final : private base_tensor<Ty, Dims...> {
        Ty a{0};
        Ty b{0};

        randi(Ty a = 0, Ty b = 1) : a(a), b(b) {
          std::random_device rd;
          std::mt19937 gen(rd());
          std::uniform_int_distribution<> dis(mu, stddev);

          static_assert(std::is_integral<Ty>::value, "input type must be integral");

          for (const auto ii : range(0, flattened_length)) {
            _data[ii] = dis(gen);
          }
        }
    };


    template <typename Ty, tensor_dim_t ...Dims>
    struct randf final : private base_tensor<Ty, Dims...> {
        Ty a{0};
        Ty b{0};

        randf(Ty a = 0, Ty b = 1) : a(a), b(b) {
          std::random_device rd;
          std::mt19937 gen(rd());
          std::uniform_int_distribution<> dis(mu, stddev);

          static_assert(std::is_floating_point<Ty>::value, "input type must be integral");

          for (const auto ii : range(0, flattened_length)) {
            _data[ii] = dis(gen);
          }
        }
    };
}

#endif //DN_TENSOR_RAND_HPP
