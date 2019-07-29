#include <limits>
#include <vector>

int smallestFactorization(int a) {
    // Corner case
    if (a == 1) return 1;

    std::vector<int> v;
    // Greedy, always find biggest factor, then reverse the result
    for (int i = 9; i > 1; --i) {
        while (a % i == 0) {
            v.push_back(i);
            a /= i;
        }
    }
    if (a != 1) return 0;

    long rev(0);
    for (auto i = v.rbegin(); i != v.rend(); ++i) {
        rev = rev * 10 + *i;
        // Overflow?
        if (rev > static_cast<int>(std::numeric_limits<int>::max())) {
            return 0;
        }
    }

    return rev;
}
