#include <unordered_map>
#include <vector>

int numEquivDominoPairs(const std::vector<std::vector<int>>& dominoes) {
    std::unordered_map<int, int> counter;
    for(const auto& domino: dominoes) {
        int x = domino[0];
        int y = domino[1];
        if (x > y) std::swap(x, y);

        int n = x * 100 + y;
        if (counter.find(n) == counter.end()) counter[n] = 0;
        ++counter[n];
    }

    int sum = 0;
    for(auto& c: counter) {
        sum += (c.second - 1) * c.second / 2;
    }

    return 0;
}
