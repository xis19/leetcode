#include <algorithm>
#include <vector>
#include <deque>

int minIncrementForUnique(std::vector<int>& A) {
    const int LEN = A.size();
    if (LEN < 2) return 0;

    std::sort(A.begin(), A.end());

    int maxSteps(0);
    std::deque<int> notUnique;
    int last = A[0];
    for (int i = 1; i < LEN; ++i) {
        const auto value = A[i];
        if (value == last) {
            notUnique.push_back(value);
        } else {
            int gap = value - last - 1;
            for (int j = 0; j < gap; ++j) {
                if (notUnique.empty()) break;
                const auto v = notUnique.front();
                notUnique.pop_front();
                maxSteps += (last + j + 1) - v;
            }
        }
        last = value;
    }

    // remaining
    while (!notUnique.empty()) {
        const auto v = notUnique.front();
        notUnique.pop_front();
        maxSteps += ++last - v;
    }

    return maxSteps;
}

