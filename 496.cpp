#include <algorithm>
#include <unordered_map>
#include <vector>

std::vector<int> nextGreaterElementCached(const std::vector<int>& findNums, const std::vector<int>& nums) {
    std::unordered_map<int, int> cache;
    std::vector<int> result;
    result.reserve(findNums.size());
    const auto NBEGIN = std::begin(nums);
    const auto NEND = std::end(nums);
    std::transform(
        std::begin(findNums), std::end(findNums), std::back_inserter(result),
        [&](int value) {
            auto cachedIter = cache.find(value);
            if (cachedIter == cache.end()) {
                auto nIter = std::find(NBEGIN, NEND, value);
                // we always have the nIter found
                cache[value] = -1;
                nIter = std::next(nIter);
                while(nIter != NEND) {
                    if (*nIter > value) {
                        cache[value] = *nIter;
                        break;
                    }
                    nIter = std::next(nIter);
                }
            }
            return cache[value];
        });
    return result;
}

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
