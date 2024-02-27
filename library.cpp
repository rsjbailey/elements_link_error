#include "library.h"

#include <iostream>
#include <elements/view.hpp>

void hello() {
    void* host{nullptr};
    cycfi::elements::view v{static_cast<cycfi::elements::host_view_handle>(host)};
    std::cout << "Hello, World!" << std::endl;
}
