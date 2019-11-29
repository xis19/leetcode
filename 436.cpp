#include <map>
#include <set>
#include <vector>

std::vector<int> findRightInterval(std::vector<std::vector<int>>& intervals) {
    const int LEN = intervals.size();
    // Maps start to its index
    std::map<int, int> startMap;
    for(int i = 0; i < LEN; ++i) {
        if (startMap.find(intervals[i][0]) == startMap.end()) {
            startMap[intervals[i][0]] = i;
        }
    }

    std::vector<int> result;
    for(int i = 0; i < LEN; ++i) {
        const auto end = intervals[i][1];
        auto rightIter = startMap.upper_bound(end);
        if (std::prev(rightIter)->first == end) rightIter = std::prev(rightIter);
        if (rightIter == startMap.end()) {
            result.push_back(-1);
        } else {
            result.push_back(rightIter->second);
        }
    }

    return result;
}
