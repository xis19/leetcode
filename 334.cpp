#include <array>
#include <limits>
#include <vector>


bool increasingTriplet(std::vector<int>& nums) {
    if (nums.size() < 3) return false;

    std::array<int, 3> seq;
    std::fill(seq.begin(), seq.end(), std::numeric_limits<int>::max());

    auto iter = nums.begin();
    seq[0] = *iter++;
    while(iter != nums.end()) {
        auto value = *iter++;
        if (value <= seq[0]) {
            seq[0] = value;
            continue;
        }
        if (value <= seq[1]) {
            seq[1] = value;
            continue;
        }
        return true;
    }
    return false;
}
