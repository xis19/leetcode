#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <vector>

int numFactoredBinaryTrees(std::vector<int>& A) {
    const int MODULUS = 1e9 + 7;
    const int LEN = A.size();

    std::sort(A.begin(), A.end());
    std::unordered_map<int, int> indexMapper;
    for (int i = 0; i < LEN; ++i) {
        indexMapper[A[i]] = i;
    }

    // Use long to avoid some overflow situation
    std::vector<long> numTrees(A.size(), 0);
    long result(0);
    for (int i = 0; i < LEN; ++i) {
        // Including itself, no subtrees
        long numSubTrees = 1;

        for (int j = 0; j < i; ++j) {
            if (A[i] % A[j] == 0) {
                const int QUOTIENT = A[i] / A[j];
                if (indexMapper.find(QUOTIENT) == indexMapper.end()) continue;
                const int k = indexMapper[QUOTIENT];
                const long subtrees = numTrees[j] * numTrees[k];
                numSubTrees += subtrees % MODULUS;
            }
        }

        numTrees[i] = numSubTrees;
        result = (result + numSubTrees) % MODULUS;
    }

    return result;
}
