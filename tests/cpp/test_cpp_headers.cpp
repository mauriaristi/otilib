#include <iostream>
#include <cmath>
#include <cassert>

extern "C" {
#include <oti/oti.h>
}

int main() {
    onumm1n3_t x, f;
    onumm1n3_set_r(2.0, &x);
    x.e1 = 1.0;

    onumm1n3_exp_to(&x, &f);

    double expected = std::exp(2.0);
    assert(std::fabs(f.r - expected) < 1e-10);
    assert(std::fabs(f.e1 - expected) < 1e-10);

    std::cout << "C++ OTI header integration tests passed successfully." << std::endl;
    return 0;
}
