#include <string>
#include <vector>

int equalSubstring(const std::string& s, const std::string& t, int maxCost) {
    const int LEN = s.size();
    std::vector<int> cost;
    for (auto i = 0; i < LEN; ++i) {
        cost.push_back(std::abs(s[i] - t[i]));
    }

    int i = 0, j = -1, c = 0;
    int maxLen = -1;
    while (j < LEN - 1) {
        ++j;
        c += cost[j];
        while (c > maxCost && i <= j) {
            c -= cost[i];
            ++i;
        }
        maxLen = std::max(maxLen, j - i + 1);
    }

    return maxLen;
}
