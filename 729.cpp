#include <limits>
#include <list>
#include <vector>

class MyCalendar {
    class Range {
        int m_min;
        int m_max;
    public:
        Range(int min = 0, int max = std::numeric_limits<int>::max()):
            m_min(min), m_max(max) {}

        bool cover(const Range& another) {
            return m_min <= another.m_min && m_max >= another.m_max;
        }

        int& min() { return m_min; }
        int& max() { return m_max; }
    };

    std::list<Range> m_rangeList;
public:
    MyCalendar() {
        // Instead of storing existing events, we store the spare time. This
        // allows us only check one range (spare range) rather than two or more
        // (recorded events).
        m_rangeList.push_back(Range());
    }

    bool book(int start, int end) {
        Range r(start, end);
        for (auto iter = m_rangeList.begin(); iter != m_rangeList.end(); ++iter) {
            if (iter->cover(r)) {
                m_rangeList.insert(iter, Range(iter->min(), r.min()));
                iter->min() = r.max();
                return true;
            }
        }

        return false;
    }
};
