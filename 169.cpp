#include <vector>

int majorityElement(const std::vector<int>& nums) {
    // Boyer-Moore algorithm
    int i;
    int count(0);
    for(auto n: nums) {
        if (count == 0) {
            i = n;
            count = 1;
        } else {
            if (n == i) ++count;
            else --count;
        }
    }
    return i;
}
