#include <vector>

int integerBreak(int n) {
    // Note:
    // 2 -> 1 * 1 = 1
    // 3 -> 1 * 2 = 2
    // 4 -> 2 * 2 = 4
    // 5 -> 2 * 3 = 6
    // 6 -> 3 * 3 = 9
    // So for a number larger or equal to 5, we should split it into 2/3/4 set.
    switch(n) {
        case 2: return 1;
        case 3: return 2;
        case 4: return 4;
    }

    int k = 1;
    while (n > 4) n -= 3, k *= 3;
    k*=n;

    return k;
}
