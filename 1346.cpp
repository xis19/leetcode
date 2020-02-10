#include <unordered_set>
#include <vector>

bool checkIfExist(const std::vector<int>& arr) {
    std::unordered_set<int> set(arr.begin(), arr.end());
    for (auto v: arr) {
        const int dbl = v * 2;
        if (set.find(dbl) != set.end()) {
            return true;
        }
    }
    return false;
}
