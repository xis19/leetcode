#include <algorithm>
#include <vector>

std::vector<int> addToArrayForm(std::vector<int>& A, int K) {
    std::reverse(A.begin(), A.end());

    for(auto& i: A) {
        i += K;
        K = i / 10;
        i = i % 10;
    }

    while(K > 0) {
        A.push_back(K % 10);
        K /= 10;
    }

    std::reverse(A.begin(), A.end());

    return A;
}

