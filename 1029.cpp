#include <algorithm>
#include <vector>

int twoCitySchedCost(const std::vector<std::vector<int>>& costs) {
    // Assume everyone go to A, then we compute the cost difference that
    // move someone from A to B.
    int cost = 0;
    for (const auto& r: costs) {
        cost += r[0];
    }

    std::vector<int> costDiff;
    std::transform(costs.begin(), costs.end(), std::back_inserter(costDiff), [](const std::vector<int>& c) { return c[1] - c[0]; });
    std::sort(costDiff.begin(), costDiff.end());

    const int LEN = costDiff.size();
    for (int i = 0; i < LEN / 2; ++i) {
        cost += costDiff[i];
    }

    return cost;
}
