#include <algorithm>
#include <unordered_map>
#include <vector>

std::vector<int> nextGreaterElement(const std::vector<int>& findNums, const std::vector<int>& nums) {
    // No cache version
    std::vector<int> result;
    result.reserve(findNums.size());
    const auto NBEGIN = std::begin(nums);
    const auto NEND = std::end(nums);
    std::transform(
        std::begin(findNums), std::end(findNums), std::back_inserter(result),
        [&](int value) {
            auto nIter = std::find(NBEGIN, NEND, value);
            // we always have the nIter found
            nIter = std::next(nIter);
            while(nIter != NEND) {
                if (*nIter > value) {
                    return *nIter;
                }
                nIter = std::next(nIter);
            }
            return -1;
        });
    return result;
}
