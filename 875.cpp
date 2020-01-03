#include <vector>

int minEatingSpeed(const std::vector<int>& piles, int H) {
    auto canEat = [&piles, &H](int K) -> bool {
        int hours = 0;
        for (auto& p: piles) {
            hours += p / K + (p % K > 0);
        }
        return hours <= H;
    };

    int l = 1, r = 2e9;
    int trial = l + (r - l) / 2;
    while (l < r) {
        if (canEat(trial)) {
            r = trial;
        } else {
            // trial won't work, so l has to be at least the next of trial
            l = trial + 1;
        }
        trial = l + (r - l) / 2;
    }

    return l;
}
