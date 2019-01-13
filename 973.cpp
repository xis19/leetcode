#include <algorithm>
#include <vector>

std::vector<std::vector<int>> kClosest(
        std::vector<std::vector<int>>& points, int K) {
    std::sort(points.begin(), points.end(),
            [&](const std::vector<int>& i, const std::vector<int>& j) {
                return i[0] * i[0] + i[1] * i[1] > j[0] * j[0] + j[1] * j[1];
            }
    );

    std::vector<std::vector<int>> result;
    for(size_t i = points.size() - K; i < points.size(); ++i) {
        result.push_back(points[i]);
    }

    return result;
}
