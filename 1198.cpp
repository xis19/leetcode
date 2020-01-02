#include <unordered_map>
#include <vector>

int smallestCommonElement(const std::vector<std::vector<int>>& mat) {
    std::unordered_map<int, int> numCount;
    for(auto r: mat) {
        for(auto v: r) {
            if (numCount.find(v) == numCount.end()) numCount[v] = 0;
            ++numCount[v];
        }
    }

    const int N = mat.size();

    int min = 1e5;
    for (auto i: numCount) {
        if (i.second == N) {
            min = std::min(min, i.first);
        }
    }
    if (min == 1e5) return -1;
    return min;
}
