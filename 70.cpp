#include <vector>

int climbStairs(int n) {
    // the last step can be 1 or 2
    // so f(n) = f(n - 1) + f(n - 2)
    static std::vector<int> v{1, 2};

    if (static_cast<int>(v.size()) >= n) {
        return v[n - 1];
    }

    int i = v.size();
    v.resize(n);
    while(i <= n) {
        v[i] = v[i - 1] + v[i - 2];
        ++i;
    }

    return v[n - 1];
}
