#include <algorithm>
#include <numeric>
#include <string>
#include <vector>

std::vector<int> diStringMatch(std::string S) {
    const int LEN = S.size();
    std::vector<int> values(LEN);
    std::iota(values.begin(), values.end(), 0);

    auto iter = values.begin();
    int nDs(0);
    S += 'I';
    for(auto ch: S) {
        if (ch == 'I') {
            std::reverse(iter, iter + nDs + 1);
            iter += nDs + 1;
            nDs = 0;
        } else {
            ++nDs;
        }
    }

    return values;
}
