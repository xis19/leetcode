#include <algorithm>
#include <tuple>
#include <utility>
#include <vector>

std::vector<std::vector<int>> intervalIntersection(
        const std::vector<std::vector<int>>& A,
        const std::vector<std::vector<int>>& B) {
    // Similiar to skyline
    typedef std::tuple<int, char, char> tuple;
    std::vector<tuple> sorted;
    for (const auto& a: A) {
        sorted.push_back(std::make_tuple(a[0], 's', 'a'));
        // Note that the intervals are CLOSED
        sorted.push_back(std::make_tuple(a[1] + 1, 'e', 'a'));
    }
    for (const auto& b: B) {
        sorted.push_back(std::make_tuple(b[0], 's', 'b'));
        sorted.push_back(std::make_tuple(b[1] + 1, 'e', 'b'));
    }

    std::sort(sorted.begin(), sorted.end(), [](const tuple& t1, const tuple& t2) {
                if (std::get<0>(t1) != std::get<0>(t2)) {
                    return std::get<0>(t1) < std::get<0>(t2);
                }
                // end should have higher priority in case you start an
                // intersection, record it then found the other interval is
                // ending.
                return std::get<1>(t1) < std::get<1>(t2);
            });

    std::vector<std::vector<int>> result;
    int numOpen = 0;
    int intersectionStart(-1);
    for (const auto& record: sorted) {
        if (std::get<1>(record) == 's') {
            ++numOpen;
            if (numOpen == 2) {
                intersectionStart = std::get<0>(record);
            }
        } else {
            --numOpen;
            if (numOpen == 1) {
                // Note we added 1 at the end
                result.push_back(std::vector<int>{intersectionStart, std::get<0>(record) - 1});
            }
        }
    }

    return result;
}
