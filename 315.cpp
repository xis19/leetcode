#include <algorithm>
#include <map>
#include <vector>

std::vector<int> countSmaller(const std::vector<int>& nums) {
    std::vector<int> result;
    result.reserve(nums.size());

    // Count before is much easier than count after
    // We count the number of appearance of each number
    std::map<int, int> numberCount;
    for (auto iter = nums.rbegin(); iter < nums.rend(); ++iter) {
        int value = *iter;
        auto lbound = numberCount.lower_bound(value);
        int totalNumbers(0);
        for (auto i = numberCount.begin(); i != lbound; ++i) {
            totalNumbers += i->second;
        }
        result.push_back(totalNumbers);
        if (numberCount.find(value) == numberCount.end()) {
            numberCount[value] = 0;
        }
        ++numberCount[value];
    }

    std::reverse(result.begin(), result.end());
    return result;
}
