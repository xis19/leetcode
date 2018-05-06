#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <vector>

int orderOfLargestPlusSign(int N, std::vector<std::vector<int>>& mines) {
    typedef std::tuple<int, int, int, int> OneSet;

    // For a given pixel, we count the 1s from left, right, top, bottom
    std::vector<std::vector<OneSet>> count(N, std::vector<OneSet>(N, std::make_tuple(0, 0, 0, 0)));

    // We use hash to faster check mines
    std::unordered_map<int, std::unordered_set<int>> mmines;
    for(auto& mine: mines) {
        mmines[mine[0]].insert(mine[1]);
    }

    // Top-Bottom, Left-Right
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            if (mmines[i].count(j) == 0) {
                std::get<0>(count[i][j]) = i > 0 ? std::get<0>(count[i - 1][j]) + 1 : 1;
                std::get<2>(count[i][j]) = j > 0 ? std::get<2>(count[i][j - 1]) + 1 : 1;
            }
        }
    }

    // Bottom-Top, Right-Left
    for(int i = N - 1; i >= 0; --i) {
        for(int j = N - 1; j >= 0; --j) {
            if (mmines[i].count(j) == 0) {
                std::get<1>(count[i][j]) = i != N - 1 ? std::get<1>(count[i + 1][j]) + 1 : 1;
                std::get<3>(count[i][j]) = j != N - 1 ? std::get<3>(count[i][j + 1]) + 1 : 1;
            }
        }
    }

    int max(0);
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            std::array<int, 4> v {{
                std::get<0>(count[i][j]),
                std::get<1>(count[i][j]),
                std::get<2>(count[i][j]),
                std::get<3>(count[i][j])
            }};

            max = std::max(max, *std::min_element(std::begin(v), std::end(v)));
        }
    }

    return max;
}
