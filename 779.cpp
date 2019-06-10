#include <functional>

int kthGrammar(int N, int K) {
    // Note N and K are 1-indexed
    // 0
    // 0 1
    // 0 1 1 0
    // 0 1 1 0 1 0 0 1
    // 0 1 1 0 1 0 0 1 1 0 0 1 0 1 1 0
    if (N == 1) {
        return 0;
    }

    int p = kthGrammar(N - 1, (K + 1) / 2);
    if (p == 0) {
        if (K % 2 == 1) {
            return 0;
        } else {
            return 1;
        }
    } else {
        if (K % 2 == 1) {
            return 1;
        } else {
            return 0;
        }
    }
}
