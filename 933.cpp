#include <queue>

class RecentCounter {
private:
    std::queue<int> pings;
public:
    RecentCounter() {}

    int ping(int t) {
        pings.push(t);
        while(t - pings.front() > 3000) pings.pop();
        return pings.size();
    }
};
