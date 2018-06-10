#include <vector>

std::vector<int> spiralOrder(const std::vector<std::vector<int>>& matrix) {
    std::vector<int> vec;

    const int M = matrix.size();
    if (M == 0) return vec;
    const int N = matrix[0].size();
    if (N == 0) return vec;

    int L(0), R(N - 1), T(0), B(M - 1);
    while(true) {
        // L->R
        if (L > R) break;
        for(int i = L; i <= R; ++i) vec.push_back(matrix[T][i]);
        ++T;
        // T->B
        if (T > B) break;
        for(int i = T; i <= B; ++i) vec.push_back(matrix[i][R]);
        --R;
        // R->L
        if (R < L) break;
        for(int i = R; i >= L; --i) vec.push_back(matrix[B][i]);
        --B;
        // B->T
        if (B < T) break;
        for(int i = B; i >= T; --i) vec.push_back(matrix[i][L]);
        ++L;
    }

    return vec;
}

#include <algorithm>
#include <iostream>
#include <iterator>
int main() {
    std::vector<std::vector<int>> m = {
        {1 ,2, 3, 4},
        {5, 6, 7, 8},
        {9,10,11,12}
    };
    auto result = spiralOrder(m);
    std::copy(result.begin(), result.end(), std::ostream_iterator<int>(std::cout, "  "));
}
