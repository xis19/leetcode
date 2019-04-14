#include <vector>

std::vector<int> sumEvenAfterQueries(std::vector<int>& A, const std::vector<std::vector<int>>& queries) {
    int sum = 0;

    for(const auto a: A) {
        if (a % 2 == 0) {
            sum += a;
        }
    }

    std::vector<int> result;
    for(const auto q: queries) {
        int index = q[1];
        int diff = q[0];
        if (A[index] % 2 == 0) {
            sum -= A[index];
        }
        A[index] += diff;
        if (A[index] % 2 == 0) {
            sum += A[index];
        }
        result.push_back(sum);
    }

    return result;
}
