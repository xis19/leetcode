#include <utility>
#include <vector>

int longestMountain(const std::vector<int>& A) {
    if (A.size() == 0) return 0;

    const int LEN = A.size();
    std::vector<std::pair<int, int>> accumulate{{0, 0}};

    {
        int last = A[0];
        for (int i = 1; i < LEN; ++i) {
            int val = A[i];
            int flg = 0;
            if (last - val > 0)
                flg = -1;
            if (last - val < 0)
                flg = 1;
            if (accumulate.back().first != flg) {
                accumulate.push_back({flg, 1});
            } else {
                ++accumulate.back().second;
            }
            last = val;
        }
    }

    int longest(0);
    {
        const int ACCLEN = accumulate.size();
        auto last = accumulate[0];
        for (int i = 1; i < ACCLEN; ++i) {
            if (last.first == 1 && accumulate[i].first == -1) {
                longest = std::max(last.second + accumulate[i].second + 1, longest);
            }
            last = accumulate[i];
        }
    }

    return longest;
}
