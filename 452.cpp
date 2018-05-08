#include <algorithm>
#include <utility>
#include <vector>

int findMinArrowShots(const std::vector<std::pair<int, int>>& points) {
    //
    //  <---------------->
    //     <--------->
    //        <----->
    //                 <------------->
    //  Sort first, then use greedy algorithm
    const int NPOINTS = points.size();
    if (NPOINTS == 0) return 0;

    std::sort(
        points.begin(),
        points.end(),
        [](std::pair<int, int>& p1, std::pair<int, int>& p2) -> bool {
            return p1.first < p2.first;
        }
    );

    int count = 1;  // we need at least one arrow
    int last_extend = points[0].second;
    for(int i = 1; i < NPOINTS; ++i) {
        const auto& p = points[i];
        if (p.first > last_extend) {
            // we need a new arrow
            ++count;
            last_extend = p.second;
        } else {
            last_extend = std::min(p.second, last_extend);
        }
    }

    return count;
}
