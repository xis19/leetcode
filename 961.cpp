#include <unordered_map>
#include <vector>


int repeatedNTimes(const std::vector<int>& A) {
    std::unordered_map<int, int> count;
    for (auto a: A) {
        if (count.find(a) == count.end()) {
            count[a] = 0;
        }
        ++count[a];
    }

    int minOccur(0);
    int minValue(0);
    for (auto& t: count) {
        if (t.second > minOccur) {
            minOccur = t.second;
            minValue = t.first;
        }
    }

    return minValue;
}

// "Majority Voting Algorithm" Boyer-Moore will not work since it requires the
// majority, that is N + 1 repeated element rather than N.
