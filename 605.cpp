#include <vector>

bool canPlaceFlowers(std::vector<int>& flowerbed, int n) {
    if (n == 0) return true;

    const int S = flowerbed.size();
    int count(0);
    for(int i = 0; i < S; ++i) {
        if (flowerbed[i] == 0) {
            int next = (i == S - 1) ? 0 : flowerbed[i + 1];
            int prev = (i == 0) ? 0 : flowerbed[i - 1];
            if (!next && !prev) {
                flowerbed[i] = 1;
                ++count;
                if (count == n) {
                    return true;
                }
            }
        }
    }
    return false;
}
