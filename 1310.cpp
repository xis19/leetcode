#include <array>
#include <vector>

std::vector<int> xorQueries(
        const std::vector<int>& arr,
        const std::vector<std::vector<int>>& queries) {
    std::array<std::vector<int>, 32> oneCount;

    for (auto i = 0; i < 32; ++i) {
        oneCount[i].push_back(0);
    }
    for (auto v: arr) {
        for (auto i = 0; i < 32; ++i) {
            oneCount[i].push_back(oneCount[i].back() + (v & 1));
            v >>= 1;
        }
    }

    std::vector<int> result;
    for (auto& q: queries) {
        auto si = q[0] + 1, ei = q[1] + 1;
        int res = 0;
        for (auto i = 31; i >= 0; --i) {
            int numOnes = oneCount[i][ei] - oneCount[i][si - 1];
            res <<= 1;
            if (numOnes > 0 && numOnes % 2 == 1) {
                res += 1;
            }
        }
        result.push_back(res);
    }

    return result;
}
