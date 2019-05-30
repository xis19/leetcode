#include <functional>
#include <vector>

std::vector<std::vector<int>> combinationSum3(int k, int n) {
    std::vector<std::vector<int>> result;
    if (k > 9) return result;
    if (n > 45) return result;

    std::vector<int> current;
    current.reserve(k);
    std::function<void(int, int, int)> build = [&](int _k, int _n, int _s) -> void {
        if (_k == 0) {
            if (_n == 0) {
                result.push_back(current);
            }
            return;
        }

        if (_n < 0) {
            return;
        }

        for(int i = _s; i <= 9; ++i) {
            if (i > _n) break;

            current.push_back(i);
            build(_k - 1, _n - i, i + 1);
            current.pop_back();
        }
    };

    build(k, n, 1);

    return result;
}
