#include <functional>
#include <iterator>
#include <vector>

int countArrangement(int N) {
    // We waste [0]
    std::vector<char> flags(N + 1, 1);

    // Prepare: For i-th position, the possible values are given
    std::vector<std::vector<int>> possibleValues(N + 1);
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            if (i % j == 0 || j % i == 0) {
                possibleValues[i].push_back(j);
            }
        }
    }

    int result = 0;

    // Recursive
    // We recursive from last to first, since 1st position can have all values.
    // starting with that will increase the number of recursions.
    std::function<void(int)> recursive = [&](int i) {
        if (i == 0) {
            ++result;
            return;
        }

        for(auto& value: possibleValues[i]) {
            if (flags[value]) {
                flags[value] = 0;
                recursive(i - 1);
                flags[value] = 1;
            }
        }
    };

    recursive(N);
    return result;
}

