#include <iostream>
#include <cmath>
#include <limits>

int reverse(int x) {
    long result = 0;
    while(x != 0) {
        result = result * 10 + x % 10;
        x /= 10;
    }
    if (result < std::numeric_limits<int>::min() || result > std::numeric_limits<int>::max())
        return 0;
    return result;
}

int main() {
    int i;
    while(std::cin >> i) {
        std::cout << reverse(i) << std::endl;
    }
}
