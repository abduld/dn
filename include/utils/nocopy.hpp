//
// Created by Abdul Dakkak on 2/21/17.
//

#ifndef DN_NOCOPY_HPP
#define DN_NOCOPY_HPP

namespace dn {
    class non_copyable
    {
    protected:
        non_copyable() = default;
        ~non_copyable() = default;

        non_copyable(non_copyable const &) = delete;
        void operator=(non_copyable const &x) = delete;
    };

}

#endif //DN_NOCOPY_HPP
