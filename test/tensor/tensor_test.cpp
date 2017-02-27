//
// Created by Abdul Dakkak on 2/22/17.
//

#include <catch.hpp>
#include <spdlog/spdlog.h>

#include "tensor/tensor.hpp"



TEST_CASE("Creating tensor should create proper shape", "[tensor_create_shape]")
{
  spdlog::set_level(spdlog::level::debug);
  dn::tensor<double, 4, 2> t{};
  const auto len = t.flattened_length;
  REQUIRE(len == 8);

  const auto rank = t.rank;
  REQUIRE(rank == 2);
}
