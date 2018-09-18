#include <algorithm>
#include <unordered_map>
#include <vector>

int projectionArea(std::vector<std::vector<int>>& grid) {
    int projX(0), projY(0), projZ(0);

    for(const auto& r: grid) {
        projX += *std::max_element(std::begin(r), std::end(r));
    }

    std::unordered_map<int, int> maxY;
    for(const auto& r: grid) {
        const int LEN = r.size();
        for(int i = 0; i < LEN; ++i) {
            if (maxY.find(i) == maxY.end()) {
                maxY[i] = r[i];
            }
            maxY[i] = std::max(maxY[i], r[i]);

            if (r[i] != 0) ++projZ;
        }
    }
    for(const auto& y: maxY) {
        projY += y.second;
    }

    return projX + projY + projZ;
}
