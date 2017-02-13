#include <set>

bool containsDuplicate(const std::vector<int>& nums) {
    return std::set<int>(std::begin(nums), std::end(nums)).size() < nums.size();
}
