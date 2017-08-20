#include <algorithm>
#include <vector>

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

std::vector<Interval> merge(const std::vector<Interval>& intervals) {
    std::vector<Interval> result;
    if (intervals.size() == 0) return result;

    std::sort(intervals.begin(), intervals.end(), [](const Interval& i1, const Interval& i2) -> bool {
        return i1.start < i2.start;
    });

    auto iter = intervals.begin();
    result.push_back(*iter++);
    while(iter != intervals.end()) {
        auto& back = result.back();
        if (back.end >= iter->start) {
            back.end = std::max(iter->end, back.end);
        } else {
            result.push_back(*iter);
        }
        ++iter;
    }

    return result;
}

