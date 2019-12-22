#include <vector>

std::vector<int> numOfBurgers_DP(int tomatoSlices, int cheeseSlices) {
    // DP: f(tomatoSlices, cheeseSlices)
    //          = (jumbo, small)
    //          = f(tomatoSlices - 4, cheeseSlices - 1) + (1, 0)
    //              if f(tomatoSlices - 4, cheeseSlices - 1) does not waste
    //          ||
    //            f(tomatoSlices - 2, cheeseSlices - 1) + (0, 1)
    //              if f(tomatoSlices - 2, cheeseSlices - 1) does not waste
    //          ||
    //              (0, 0) implies waste
    std::vector<std::vector<std::vector<int>>> dp(
            tomatoSlices + 1, std::vector<std::vector<int>>(
                cheeseSlices + 1, std::vector<int>{}));
    dp[0][0] = std::vector<int>{0, 0};
    for (int i = 0; i <= tomatoSlices; ++i) {
        for (int j = 0; j <= cheeseSlices; ++j) {

            if (i >= 4 && j >= 1) {
                auto& c1 = dp[i - 4][j - 1];
                if (c1.size() != 0) {
                    dp[i][j] = std::vector<int>{c1[0] + 1, c1[1]};
                    continue;
                }
            }

            if (i >= 2 && j >= 1) {
                auto& c2 = dp[i - 2][j - 1];
                if (c2.size() != 0) {
                    dp[i][j] = std::vector<int>{c2[0], c2[1] + 1};
                    continue;
                }
            }
        }
    }
    return dp.back().back();
}

std::vector<int> numOfBurgersSlow(int tomatoSlices, int cheeseSlices) {
    if (cheeseSlices * 2 > tomatoSlices || cheeseSlices * 4 < tomatoSlices) {
        return std::vector<int>{};
    }
    int jumbo(0);
    while (cheeseSlices * 2 < tomatoSlices) {
        ++jumbo;
        tomatoSlices -= 4;
        cheeseSlices -= 1;
    }
    if (cheeseSlices * 2 > tomatoSlices) {
        return std::vector<int>{};
    }
    return std::vector<int>{jumbo, cheeseSlices};
}

std::vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
    // Idiot... Solve the eqn with integer solution
    //  4 * jumbo + 2 * small = tomato
    //  jumbo + small = cheese
    if (tomatoSlices % 2 == 1 || tomatoSlices / 2 - cheeseSlices < 0) {
        return std::vector<int>{};
    }
    int jumbo = tomatoSlices / 2 - cheeseSlices;
    int small = cheeseSlices - jumbo;
    if (small < 0) {
        return std::vector<int>{};
    }
    return std::vector<int>{jumbo, small};
}
