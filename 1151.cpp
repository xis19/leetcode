#include <numeric>
#include <vector>

int minSwaps(const std::vector<int>& data) {
    // We run two loops
    // In the first loop, we count the number of 1s as N
    // In the second loop, we look for a width N window with least 0s

    const int LEN = data.size();
    int N = std::accumulate(data.begin(), data.end(), 0);

    int currentWindowZero = N - std::accumulate(data.begin(), data.begin() + N, 0);
    int minZero = currentWindowZero;
    for(int i = N; i < LEN; ++i) {
        currentWindowZero += (data[i] == 0) - (data[i - N] == 0);
        minZero = std::min(minZero, currentWindowZero);
    }

    return minZero;
}

