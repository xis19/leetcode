#include <vector>

int totalHammingDistance(const std::vector<int>& nums) {
    const int NBITS = sizeof(int) * 8;
    const int N = nums.size();
    std::vector<int> bitsCount(NBITS, 0);

    for(auto v: nums) {
        for(int i = 0; i < NBITS; ++i) {
            if (v & 1) ++bitsCount[i];
            v >>= 1;
        }
    }

    int result = 0;
    for(auto c: bitsCount) {
        result += c * (N - c);
    }

    return result;
}
