cmake_minimum_required(VERSION 3.1)
project(dn)


enable_language(CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_COLOR_MAKEFILE ON)
set(VERBOSE_BUILD ON)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)


# Change all `dn` to your project name!
set(dn-build_tests ON CACHE BOOL "Whether to build tests")

# Enable C++14
set (CMAKE_CXX_STANDARD 14)


##################################
# Includes
##################################
include_directories(
  ${PROJECT_SOURCE_DIR}/src
  ${PROJECT_SOURCE_DIR}/include
  ${PROJECT_SOURCE_DIR}/tests
  ${PROJECT_SOURCE_DIR}/vendor/catch
  ${PROJECT_SOURCE_DIR}/vendor/spdlog
  ${PROJECT_SOURCE_DIR}/vendor/backward
)

##################################
# Sources
##################################

set(SOURCES
  src/main.cpp
  include/tensor/tensor.hpp
  include/utils/alloc.hpp
  include/utils/error.hpp
  include/utils/compat.hpp
  include/utils/timer.hpp
  include/utils/mpl.hpp
  include/utils/utils.hpp
  include/utils/range.hpp
  include/tensor/zeros.hpp include/tensor/randn.hpp include/tensor/base.hpp include/utils/nocopy.hpp include/linalg/dot.hpp include/compute/compute.hpp include/compute/graph.hpp include/layers/layers.hpp include/layers/convolution.hpp include/layers/tanh.hpp include/layers/exp.hpp include/layers/log.hpp include/linalg/reduce.hpp include/layers/relu.hpp include/tensor/ones.hpp include/linalg/linalg.hpp include/layers/mulc.hpp include/layers/linear.hpp include/layers/log_sigmoid.hpp include/layers/sqrt.hpp include/layers/square.hpp include/layers/sigmoid.hpp include/layer/base.hpp include/layer/flatten.hpp test/tensor/tensor_test.cpp include/compute/variable.hpp include/tensor/rand.hpp include/compute/weights.hpp include/optimizer/rmsprop.hpp include/optimizer/sgd.hpp include/layer/info.hpp include/layer/kind.hpp include/layer/clamp.hpp include/tensor/shape.hpp)

##################################
# Build
##################################

add_executable(dn ${SOURCES})

##################################
# Tests
##################################

if (dn-build_tests)
    enable_testing()

    add_executable(dn-test test/dn_test.cpp test/test_main.cpp)
    target_include_directories(dn-test PUBLIC ${Catch_INCLUDE_DIR})
    target_link_libraries(dn-test dn)


    add_test(dn_test dn-test)
endif()
