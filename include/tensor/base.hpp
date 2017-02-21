//
// Created by Abdul Dakkak on 2/21/17.
//

#ifndef DN_BASE_HPP
#define DN_BASE_HPP

#include <array>
#include "utils/utils.hpp"

namespace dn {
    using tensor_dim_t = int;
    template <typename Ty, tensor_dim_t ...Dims>
    struct tensor_base : public non_copyable {
        using value_type = Ty;
        static constexpr tensor_dim_t rank = sizeof...(Dims);
        static constexpr auto dims = std::array<tensor_dim_t, rank>(Dims...);
        static constexpr size_t flattened_length = mpl::mul<Dims...>::value;
        static constexpr size_t byte_count = sizeof(flattened_length) * sizeof(value_type);

        tensor_dim_t nrows() const {
          static_assert(rank >= 1);
          return dims[rank - 1];
        }

        tensor_dim_t ncols() const {
          static_assert(rank >= 2);
          return dims[rank - 2];
        }

        tensor_dim_t ndepth() const {
          static_assert(rank >= 3);
          return dims[rank - 3];
        }

        const Ty getData() const {
          return _data;
        }

        template <typename T>
        void operator+=(const T & s) {
          for (const auto ii : range(0, flattened_length)) {
            _data[ii] += s;
          }
        }

        template <typename T>
        void operator*=(const T & s) {
          for (const auto ii : range(0, flattened_length)) {
            _data[ii] *= s;
          }
        }

        template <typename T, int len>
        std::enable_if_t<rank == 1, void>
        operator+=(const tensor_base<T, len> & vec) {
          const auto vecData = vec.getData();
          for (const auto ii : range(0, flattened_length)) {
            _data[ii] += vecData[ii];
          }
        }

        template <typename T, int len>
        std::enable_if_t<rank == 1, void>
        operator*=(const tensor_base<T, len> & vec) {
          const auto vecData = vec.getData();
          for (const auto ii : range(0, flattened_length)) {
            _data[ii] *= vecData[ii];
          }
        }


        template <typename T, int x1, int x2>
        std::enable_if_t<rank == 2, void>
        operator+=(const tensor_base<T, x1, x2> & vec) {
          const auto vecData = vec.getData();
          const size_t inner_dim = dims[rank - 1];
          const size_t outer_dim = flattened_length / inner_dim;
          for (const auto ii : range(0, outer_dim)) {
            for (const auto jj : range(0, inner_dim)) {
              _data[ii * inner_dim + jj] += vecData[jj];
            }
          }
        }

        template <typename T, int x1, int x2>
        std::enable_if_t<rank == 2, void>
        operator*=(const tensor_base<T, x1, x2> & vec) {
          const auto vecData = vec.getData();
          const size_t inner_dim = dims[rank - 1];
          const size_t outer_dim = flattened_length / inner_dim;
          for (const auto ii : range(0, outer_dim)) {
            for (const auto jj : range(0, inner_dim)) {
              _data[ii * inner_dim + jj] *= vecData[jj];
            }
          }
        }

        template <typename OpF>
        void op(const OpF && F) {
          for (const auto ii : range(0, flattened_length)) {
            _data[ii] = std::forward<>(_data[ii]);
          }
        }

    protected:
        Ty * _data{nullptr};
    };
};

#endif //DN_BASE_HPP
