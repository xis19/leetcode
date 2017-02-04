#include <limits>
#include <vector>


int findPoisonedDuration(const std::vector<int>& timeSeries, int duration) {
    int accumulated = duration * timeSeries.size();
    int lastAttackEnd = std::numeric_limits<int>::min();

    for(auto time: timeSeries) {
        if (lastAttackEnd > time) {
            accumulated -= lastAttackEnd - time;
        }
        lastAttackEnd = time + duration;
    }

    return accumulated;
}

int findPoisonedDuration_slow(const std::vector<int>& timeSeries, int duration) {
    int accumulated = 0;
    int lastAttack = std::numeric_limits<int>::min();

    for(auto time: timeSeries) {
        accumulated += duration;
        if (lastAttack + duration > time) {
            accumulated -= lastAttack + duration - time;
        }
        lastAttack = time;
    }

    return accumulated;
}
