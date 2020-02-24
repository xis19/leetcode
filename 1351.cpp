#include <algorithm>
#include <vector>


int countNegatives(const std::vector<std::vector<int>>& grid) {
    int count(0);
    for(auto& r: grid) {
        if (r[0] < 0) {
            count += r.size();
            continue;
        }
        auto upper = std::upper_bound(r.rbegin(), r.rend(), -1);
        count += std::distance(r.rbegin(), upper);
    }
    return count;
}
