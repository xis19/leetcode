#include <vector>

int singleNumber(const std::vector<int>& nums) {
    int result = 0;
    for(const int n: nums) {
        result ^= n;
    }
    return result;
}
