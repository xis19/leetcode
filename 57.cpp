#include <vector>

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};


std::vector<Interval> insert(std::vector<Interval>& intervals, Interval newInterval) {
    std::vector<Interval> result;
    result.reserve(intervals.size() + 1);

    size_t insertPos = 0;
    while(insertPos < intervals.size()) {
        if (intervals[insertPos].end >= newInterval.start) break;

        result.push_back(intervals[insertPos]);
        ++insertPos;
    }

    if (insertPos == intervals.size()) {
        result.push_back(newInterval);
        return result;
    }

    if (intervals[insertPos].end < newInterval.start) {
        result.push_back(intervals[insertPos]);
        result.push_back(newInterval);
    } else if (intervals[insertPos].start > newInterval.end) {
        result.push_back(newInterval);
        result.push_back(intervals[insertPos]);
    } else {
        result.push_back(Interval(
            std::min(newInterval.start, intervals[insertPos].start),
            std::max(newInterval.end, intervals[insertPos].end)
        ));
    }

    ++insertPos;
    for(; insertPos < intervals.size(); ++insertPos) {
        if (intervals[insertPos].start > result.back().end) {
            result.push_back(intervals[insertPos]);
        } else {
            result.back().end = std::max(result.back().end, intervals[insertPos].end);
        }
    }

    return result;
}
