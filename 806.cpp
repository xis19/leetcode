#include <algorithm>
#include <string>
#include <vector>

std::vector<int> numberOfLines(const std::vector<int>& widths, const std::string& S) {
    int nL(0), nI(0);
    for (auto ch: S) {
        const auto w = widths[ch - 'a'];
        if (nI + w > 100) {
            ++nL;
            nI = w;
        } else {
            nI += w;
        }
    }
    return std::vector<int>{nL + (nI ? 1 : 0), nI};
}
