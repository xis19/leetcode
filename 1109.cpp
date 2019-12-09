#include <unordered_map>
#include <vector>

std::vector<int> corpFlightBookings(const std::vector<std::vector<int>>& bookings, int n) {
    std::unordered_map<int, int> rangeCriticalPoint;
    for (auto booking: bookings) {
        auto s = booking[0], e = booking[1], v = booking[2];
        if (rangeCriticalPoint.find(s) == rangeCriticalPoint.end()) {
            rangeCriticalPoint[s] = 0;
        }
        if (rangeCriticalPoint.find(e + 1) == rangeCriticalPoint.end()) {
            rangeCriticalPoint[e + 1] = 0;
        }
        rangeCriticalPoint[s] += v;
        rangeCriticalPoint[e + 1] -= v;
    }

    std::vector<int> result(n);
    int v(0);
    for (int i = 1; i < n + 1; ++i) {
        if (rangeCriticalPoint.find(i) != rangeCriticalPoint.end()) {
            v += rangeCriticalPoint[i];
        }
        result[i - 1] = v;
    }

    return result;
}

