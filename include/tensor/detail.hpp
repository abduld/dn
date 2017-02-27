//
// Created by Abdul Dakkak on 2/27/17.
//

#ifndef DN_TENSOR_DETAIL_HPP
#define DN_TENSOR_DETAIL_HPP

#include "utils/utils.hpp"
#include <tuple>
#include <type_traits>

namespace dn {
namespace detail {
  //        template<size_t... ii>
  //        struct index_sequence {
  //            typedef index_sequence<ii...> type;
  //            using value_type = size_t;
  //
  //            static constexpr std::size_t size() noexcept { return
  //            sizeof...(ii); }
  //        };
  //
  //        template <template <size_t ii, size_t ... iis > class seq>
  //        using rest = typename index_sequence<iis...>::type;
  //
}
}

#endif // DN_TENSOR_DETAIL_HPP
