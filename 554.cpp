#include <vector>
#include <unordered_map>

int leastBricks(const std::vector<std::vector<int>>& wall) {
    std::unordered_map<int, int> mapper;
    for(const auto& r: wall) {
        int accumu(0);
        for(auto s: r) {
            ++mapper[accumu += s];
        }
        // the last brick should not have a final hole.
        mapper[accumu] = 0;
    }

    int maxHoles(0);
    for(const auto& m: mapper) {
        if (m.second > maxHoles) maxHoles = m.second;
    }

    return wall.size() - maxHoles;
}
