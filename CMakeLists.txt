cmake_minimum_required(VERSION 3.1)
project(dn CXX)


enable_language(CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_COLOR_MAKEFILE ON)
set(VERBOSE_BUILD ON)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)


# Change all `dn` to your project name!
set(dn-build_tests ON CACHE BOOL "Whether to build tests")

# Enable C++14
set (CMAKE_CXX_STANDARD 11)


#if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fdiagnostics-color")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ferror-limit=0")
#endif()

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
  include/tensor/tensor.hpp
  include/utils/alloc.hpp
  include/utils/error.hpp
  include/utils/compat.hpp
  include/utils/timer.hpp
  include/utils/mpl.hpp
  include/utils/utils.hpp
  include/utils/range.hpp
  include/tensor/zeros.hpp
  include/tensor/randn.hpp
  include/tensor/base.hpp
  include/utils/nocopy.hpp
  include/linalg/dot.hpp
  include/compute/compute.hpp
  include/compute/graph.hpp
  include/layer/layer.hpp
  include/layer/convolution.hpp
  include/layer/tanh.hpp
  include/layer/exp.hpp
  include/layer/log.hpp
  include/linalg/reduce.hpp
  include/layer/relu.hpp
  include/tensor/ones.hpp
  include/linalg/linalg.hpp
  include/layer/mulc.hpp
  include/layer/linear.hpp
  include/layer/log_sigmoid.hpp
  include/layer/sqrt.hpp
  include/layer/square.hpp
  include/layer/sigmoid.hpp
  include/layer/base.hpp
  include/layer/flatten.hpp
  test/tensor/shape_test.cpp
  include/compute/variable.hpp
  include/tensor/rand.hpp
  include/compute/weights.hpp
  include/optimizer/rmsprop.hpp
  include/optimizer/sgd.hpp
  include/layer/info.hpp
  include/layer/kind.hpp
  include/layer/clamp.hpp
  include/tensor/shape.hpp
  )

##################################
# Build
##################################

add_library(dn STATIC ${SOURCES})
add_executable(dnx src/main.cpp)
target_link_libraries(dnx dn)

##################################
# Tests
##################################

if (dn-build_tests)
    enable_testing()

    add_executable(dn-test test/test_main.cpp test/tensor/shape_test.cpp test/tensor/tensor_test.cpp)
    target_include_directories(dn-test PUBLIC ${Catch_INCLUDE_DIR})
    target_link_libraries(dn-test dn)

    add_test(dn_test dn-test)
endif()
