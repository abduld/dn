//
// Created by Abdul Dakkak on 2/21/17.
//

#ifndef DN_UTILS_TIMER_HPP
#define DN_UTILS_TIMER_HPP

#include <chrono>

namespace dn {
static std::chrono::time_point<std::chrono::high_resolution_clock> now() {
  return std::chrono::high_resolution_clock::now();
}
}

#endif // DN_UTILS_TIMER_HPP
