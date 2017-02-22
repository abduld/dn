//
// Created by Abdul Dakkak on 2/21/17.
//


#include <catch.hpp>
#include <spdlog/spdlog.h>

#include "tensor/tensor.hpp"



TEST_CASE("Creating tensor should create propper shape", "[tensor_create_shape]")
{
  spdlog::set_level(spdlog::level::debug);
 using shape = dn::shape<4, 2>;
  const auto len = shape::flattened_length;
  REQUIRE(len == 8);

  const auto rank = shape::rank;
  REQUIRE(rank == 2);
}
