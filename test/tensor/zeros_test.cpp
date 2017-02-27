//
// Created by Abdul Dakkak on 2/27/17.
//

#include <catch.hpp>
#include <spdlog/spdlog.h>

#include "tensor/tensor.hpp"



TEST_CASE("Creating zeros should create proper shape", "[zeros_create_shape]")
{
  spdlog::set_level(spdlog::level::debug);
  dn::zeros<double, 4, 2> t{};
  const auto len = t.flattened_length;
  REQUIRE(len == 8);

  const auto rank = t.rank;
  REQUIRE(rank == 2);
}

TEST_CASE("Creating zeros should create a zeros tensor", "[zeros_check_values]")
{
  spdlog::set_level(spdlog::level::debug);
  dn::zeros<double, 2> zeros{};

  const auto val = zeros[0];
  REQUIRE(val == 0);
}
