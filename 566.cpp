#include <vector>

std::vector<std::vector<int>> matrixReshape(const std::vector<std::vector<int>>& nums, int r, int c) {
    const int R = nums.size();
    if (R == 0) return nums;
    const int C = nums[0].size();
    if (C == 0 || R * C != r * c) return nums;

    std::vector<std::vector<int>> result(r);
    for(auto& v: result) v.resize(c);

    int cc = 0, rr = 0;
    for(const auto& ROW: nums) {
        for(const auto& val: ROW) {
            result[rr][cc] = val;

            ++cc;
            if (cc == c) {
                ++rr;
                cc = 0;
            }
        }
    }

    return result;
}
