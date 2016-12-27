#include <functional>
bool isPowerOfTwo(int n) {
    if (n <= 0) return false;

    std::function<bool(int)> recursive = [&](int k) -> bool {
        if (k == 1)
            return true;
        return !(k & 1)  && recursive(k >> 1);
    };

    std::function<bool(int)> trick = [&](int k) -> bool {
        return !(k & (k - 1));
    };

    return trick(n);
}
