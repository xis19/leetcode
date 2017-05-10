#include <set>
#include <vector>

int distributeCandies(const std::vector<int>& candies) {
    std::set<int> types;
    for(auto c: candies) {
        types.insert(c);
    }
    auto numTypes = types.size();
    return std::min(candies.size() / 2, numTypes);
}
