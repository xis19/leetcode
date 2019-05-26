#include <sstream>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>

std::vector<std::vector<int>> findSubsequences(const std::vector<int>& nums) {
    const int LEN = nums.size();
    std::unordered_set<std::string> hashSet;
    std::vector<std::vector<int>> result;

    auto vectorHash = [](const std::vector<int>& v) -> std::string {
        std::stringstream ss;
        for(auto val: v) {
            ss << val << ' ';
        }
        return ss.str();
    };

    auto pushResult = [&hashSet, &result, vectorHash](std::vector<int>&& v) {
        const auto hash = vectorHash(v);
        if (hashSet.find(hash) != hashSet.end()) return;
        hashSet.insert(hash);
        result.emplace_back(v);
    };

    for(int i = 1; i < LEN; ++i) {
        const int N = nums[i];
        const int LEN_EXISTING = result.size();
        for(int j = 0; j < LEN_EXISTING; ++j) {
            if (result[j].back() <= N) {
                std::vector<int> x(result[j].begin(), result[j].end());
                x.push_back(N);
                pushResult(std::forward<std::vector<int>>(x));
            }
        }
        // Special case - two elements
        for(int j = 0; j < i; ++j) {
            if (nums[j] <= N) {
                pushResult(std::vector<int>{nums[j], N});
            }
        }
    }

    return result;
}
