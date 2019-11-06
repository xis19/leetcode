#include <unordered_set>
#include <vector>

bool canCross(const std::vector<int>& stones) {
    // DP:
    // f(i) maps i to a set of steps it can jump
    // e.g.
    //
    // Stones: {0, 1, 3, 5, 6, 8, 12, 17}
    //
    //    0    1     3     5     6     8     12    17
    // 0  0
    // 1  1,2
    // 3  -    1,2,3
    // 5  -    -     1,2,3
    // 6  -    -     2,3,4 1,2
    // 8  -    -     -     2,3,4 1,2,3
    // 12 -    -     -     -     -     3,4,5
    // 17 -    -     -     -     -     -     -     4,5,6
    const int NUM_STONES = stones.size();

    std::vector<std::unordered_set<int>> possibleJumps;
    // For the 0th stone
    possibleJumps.emplace_back(std::unordered_set<int>{1});

    for (int i = 1; i < NUM_STONES; ++i) {
        possibleJumps.emplace_back(std::unordered_set<int>());
        for (int j = 0; j < i; ++j) {
            const int DIFF = stones[i] - stones[j];
            if (possibleJumps[j].find(DIFF) != possibleJumps[j].end()) {
                possibleJumps[i].insert(DIFF - 1);
                possibleJumps[i].insert(DIFF);
                possibleJumps[i].insert(DIFF + 1);
            }
        }
    }

    return !possibleJumps.back().empty();
}
