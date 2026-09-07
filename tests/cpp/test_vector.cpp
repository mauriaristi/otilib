#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>

int main() {
    std::vector<double> a;
    a.resize(10, 5.35);

    assert(a.size() == 10);
    for (size_t i = 0; i < a.size(); ++i) {
        assert(std::fabs(a[i] - 5.35) < 1e-12);
    }

    std::cout << "C++ vector tests passed successfully." << std::endl;
    return 0;
}
