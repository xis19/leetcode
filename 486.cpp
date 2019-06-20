#include <functional>
#include <unordered_map>
#include <vector>

bool PredictTheWinner(const std::vector<int>& nums) {
    // For an subarray defined by start index/end index, store the score the
    // first player and the second player can get.
    // history[start index << 8 + end index]<first player score, second player score>
    // As the length of the array is less than 20, use char
    std::unordered_map<int, std::pair<int, int>> history;

    std::function<void(int, int)> builder = [&nums, &history, &builder](int l, int r) -> void{
        const int HASH = (l << 8) + r;
        auto find = history.find(HASH);
        if (find != history.end()) {
            return;
        }

        if (l == r) {
            // Only one single integer
            history[HASH] = std::make_pair(nums[l], 0);
            return;
        }

        // Construct the DP map
        builder(l + 1, r);
        builder(l, r - 1);

        const int LHASH = ((l + 1) << 8) + r;
        const int RHASH = (l << 8) + r - 1;
        const auto& lResult = history[LHASH];
        const auto& rResult = history[RHASH];

        auto l2nd = lResult.second + nums[l];
        auto r2nd = rResult.second + nums[r];

        if (l2nd > r2nd) {
            history[HASH] = std::make_pair(l2nd, lResult.first);
        } else {
            history[HASH] = std::make_pair(r2nd, rResult.first);
        }
    };

    builder(0, nums.size() - 1);

    auto& result = history[nums.size() - 1];
    return result.first >= result.second;
}

int main() {
    PredictTheWinner(std::vector<int>{1, 5, 2});
}
