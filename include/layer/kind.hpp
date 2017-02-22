//
// Created by Abdul Dakkak on 2/22/17.
//

#ifndef DN_LAYER_LAYERS_HPP
#define DN_LAYER_LAYERS_HPP

namespace dn {
namespace layer {
  enum kind : uint8_t {
    none,
    convolution,
    exp,
    flatten,
    linear,
    log,
    log_sigmoid,
    mulc,
    relu,
    sigmoid,
    sqrt,
    square,
    tanh,
  };
}
}

#endif // DN_LAYER_LAYERS_HPP
