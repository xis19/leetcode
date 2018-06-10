#include <vector>

std::vector<std::vector<int>> generateMatrix(int n) {
    std::vector<std::vector<int>> result(n, std::vector<int>(n, 0));

    int L(0), R(n - 1), T(0), B(n - 1);
    int v(1);
    while(true) {
        if (L > R) break;
        for(int i = L; i <= R; ++i) result[T][i] = v++;
        ++T;
        if (T > B) break;
        for(int i = T; i <= B; ++i) result[i][R] = v++;
        --R;
        if (R < L) break;
        for(int i = R; i >= L; --i) result[B][i] = v++;
        --B;
        if (B < T) break;
        for(int i = B; i >= T; --i) result[i][L] = v++;
        ++L;
    }

    return result;
}
