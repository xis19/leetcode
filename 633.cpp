#include <cmath>

bool judgeSquareSum(int c) {
    for(int i = 0; i <= std::sqrt(c / 2); ++i) {
        int remaining = c - i * i;
        int root = static_cast<int>(std::sqrt(remaining));
        if (root * root == remaining) return true;
    }
    return false;
}
