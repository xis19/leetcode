#include <iostream>
#include <cmath>

bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }

    const int nDigits = std::log10(x) + 1;
    for(int i = 0; i < nDigits / 2; ++i) {
        if (x / static_cast<int>(std::pow(10, i)) % 10 != x / static_cast<int>(std::pow(10, nDigits - i - 1)) % 10) {
            return false;
        }
    }
    return true;
}

int main() {
    int i;
    while(std::cin >> i) {
        std::cout  << isPalindrome(i) << std::endl;
    }
}
