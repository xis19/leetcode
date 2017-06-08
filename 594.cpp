#include <unordered_map>
#include <vector>

int findLHS(std::vector<int>& nums) {
    std::unordered_map<int, int> count;
    for(auto n: nums) {
        ++count[n];
    }

    int maxLen = 0;
    for(auto i: count) {
        if (count.find(i.first + 1) != count.end()) {
            maxLen = std::max(maxLen, i.second + count[i.first + 1]);
        }
    }

    return maxLen;
}

