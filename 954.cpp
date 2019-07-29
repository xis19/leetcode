#include <algorithm>
#include <unordered_set>
#include <vector>


bool canReorderDoubled(std::vector<int>& A) {
    // Corner case: must use multiset since elements in A is not unique
    std::unordered_multiset<int> set(A.begin(), A.end());

    std::sort(A.begin(), A.end(),
              [](const int a, const int b) { return std::abs(a) < std::abs(b); });

    for (auto v: A) {
        auto findV = set.find(v);
        if (findV == set.end()) continue;

        // 0 is a special case, since 0 * 0 = 0
        if (v == 0) {
            set.erase(findV);
            auto find0 = set.find(0);
            if (find0 == set.end()) return false;
            set.erase(find0);
            continue;
        }

        auto find2V = set.find(v * 2);
        if (find2V == set.end()) return false;
        set.erase(findV);
        set.erase(find2V);
    }

    return set.empty();
}
