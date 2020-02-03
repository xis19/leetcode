#include <vector>


int numWays(int steps, int arrLen) {
    // Note that the number of steps will limit the farthest distance the
    // pointer could reach, so actual array len is less than steps
    const int MODULUS = 1e9 + 7;
    const int LEN = std::min(steps, arrLen);

    std::vector<long> dpPrev(LEN, 0);
    std::vector<long> dp(LEN);
    dpPrev[0] = 1;

    for (int i = 0; i < steps; ++i) {
        dp[0] = (dpPrev[0] + dpPrev[1]) % MODULUS;
        dp[LEN - 1] = (dpPrev[LEN - 2] + dpPrev[LEN - 1]) % MODULUS;
        for (int j = 1; j < LEN - 1; ++j) {
            dp[j] = (dpPrev[j - 1] + dpPrev[j] + dpPrev[j + 1]) % MODULUS;
        }
        std::swap(dpPrev, dp);
    }

    return dpPrev[0];
}
