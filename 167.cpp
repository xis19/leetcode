#include <algorithm>
#include <vector>

std::vector<int> twoSum(const std::vector<int>& numbers, int target) {
    std::vector<int> result;
    for(auto iter = numbers.begin(); iter != numbers.end(); ++iter) {
        int expected = target - *iter;
        if (expected < *iter) {
            break;
        }
        auto foundIter = std::lower_bound(iter + 1, numbers.end(), expected);
        if (foundIter != numbers.end() && *foundIter == expected) {
            result.push_back(iter - numbers.begin() + 1);
            result.push_back(foundIter - numbers.begin() + 1);
            break;
        }
    }
    return result;
}
