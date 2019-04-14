#include <algorithm>
#include <vector>

std::vector<int> powerfulINtegers(int x, int y, int bound) {
    std::vector<int> sx, sy;
    auto powers = [bound](int v, std::vector<int>& s) -> void {
        s.push_back(1);
        // CORNER CASE!
        if (v == 1) return;
        while(s.back() <= bound) {
            s.push_back(s.back() * v);
        }
    };
    powers(x, sx);
    powers(y, sy);

    std::vector<int> result;
    for(auto xx: sx) {
        for(auto yy: sy) {
            if (xx + yy <= bound) {
                result.push_back(xx + yy);
            }
        }
    }
    std::sort(result.begin(), result.end());
    auto newEnd = std::unique(result.begin(), result.end());

    return std::vector<int>(result.begin(), newEnd);
}
