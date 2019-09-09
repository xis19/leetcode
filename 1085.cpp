#include <algorithm>
#include <vector>

int sumOfDigits(const std::vector<int>& A) {
    int min = *std::min_element(A.begin(), A.end());
    int sum = 0;
    while(min > 0) {
        sum += min % 10;
        min /= 10;
    }
    return sum % 2 == 0;
}
