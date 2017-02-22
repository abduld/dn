//
// Created by Abdul Dakkak on 2/21/17.
//

#ifndef DN_base_tensor_HPP
#define DN_base_tensor_HPP

#include "tensor/shape.hpp"
#include "utils/utils.hpp"
#include <array>

namespace dn {
template <typename Ty, index_type... Dims>
struct base_tensor : public non_copyable {
  using value_type                       = Ty;
  using shape                            = shape<Dims...>;
  static constexpr auto rank             = shape::rank;
  static constexpr auto dims             = shape::dims;
  static constexpr auto flattened_length = shape::flattened_length;
  static constexpr size_t byte_count =
      sizeof(flattened_length) * sizeof(value_type);

  explicit base_tensor() {
    _data = new Ty[flattened_length];
  }
  ~base_tensor() {
    delete[] _data;
  }
  constexpr index_type nrows() const {
    static_assert(rank >= 1,
                  "expected the tensor to have a rank greater than 1");
    return dims[rank - 1];
  }

  constexpr index_type ncols() const {
    static_assert(rank >= 2,
                  "expected the tensor to have a rank greater than 2");
    return dims[rank - 2];
  }

  constexpr index_type ndepth() const {
    static_assert(rank >= 3,
                  "expected the tensor to have a rank greater than 3");
    return dims[rank - 3];
  }

  Ty* getData() const noexcept {
    return _data;
  }

  template <typename T>
  void operator+=(const T& s) {
    for (const auto ii : range(0, flattened_length)) {
      _data[ii] += s;
    }
  }

  template <typename T>
  void operator*=(const T& s) {
    for (const auto ii : range(0, flattened_length)) {
      _data[ii] *= s;
    }
  }

  template <typename T, int len>
  mpl::enable_if_t<rank == 1, void> operator+=(const base_tensor<T, len>& vec) {
    const auto vecData = vec.getData();
    for (const auto ii : range(0, flattened_length)) {
      _data[ii] += vecData[ii];
    }
  }

  template <typename T, int len>
  mpl::enable_if_t<rank == 1, void> operator*=(const base_tensor<T, len>& vec) {
    const auto vecData = vec.getData();
    for (const auto ii : range(0, flattened_length)) {
      _data[ii] *= vecData[ii];
    }
  }

  template <typename T, int len>
  mpl::enable_if_t<rank == 1, void> operator-=(const base_tensor<T, len>& vec) {
    const auto vecData = vec.getData();
    for (const auto ii : range(0, flattened_length)) {
      _data[ii] -= vecData[ii];
    }
  }

  template <typename T, int x1, int x2>
  mpl::enable_if_t<rank == 2, void>
      operator+=(const base_tensor<T, x1, x2>& vec) {
    const auto vecData     = vec.getData();
    const size_t inner_dim = dims[rank - 1];
    const size_t outer_dim = flattened_length / inner_dim;
    for (const auto ii : range(0, outer_dim)) {
      for (const auto jj : range(0, inner_dim)) {
        _data[ii * inner_dim + jj] += vecData[jj];
      }
    }
  }

  template <typename T, int x1, int x2>
  mpl::enable_if_t<rank == 2, void>
      operator*=(const base_tensor<T, x1, x2>& vec) {
    const auto vecData     = vec.getData();
    const size_t inner_dim = dims[rank - 1];
    const size_t outer_dim = flattened_length / inner_dim;
    for (const auto ii : range(0, outer_dim)) {
      for (const auto jj : range(0, inner_dim)) {
        _data[ii * inner_dim + jj] *= vecData[jj];
      }
    }
  }

  template <typename T, int x1, int x2>
  mpl::enable_if_t<rank == 2, void>
      operator-=(const base_tensor<T, x1, x2>& vec) {
    const auto vecData     = vec.getData();
    const size_t inner_dim = dims[rank - 1];
    const size_t outer_dim = flattened_length / inner_dim;
    for (const auto ii : range(0, outer_dim)) {
      for (const auto jj : range(0, inner_dim)) {
        _data[ii * inner_dim + jj] -= vecData[jj];
      }
    }
  }

  template <typename OpF>
  void op(const OpF&& F) {
    for (const auto ii : range(0, flattened_length)) {
      _data[ii] = std::forward<>(_data[ii]);
    }
  }

protected:
  Ty* _data{nullptr};
};
};

#endif // DN_base_tensor_HPP
