#include <vector>

int maxDistToClosest(const std::vector<int>& seats) {
    int maxDistance(0);
    // Be aware the two boundaries
    auto iter = seats.begin();
    if (*iter == 0) {
        while(iter != seats.end() && *iter == 0) ++maxDistance, ++iter;
    }

    int currentNumberOfZeros = 0;
    for(; iter !=seats.end(); ++iter) {
        if (*iter == 1) {
            maxDistance = std::max(maxDistance, (currentNumberOfZeros + 1) / 2);
            currentNumberOfZeros = 0;
        } else {
            ++currentNumberOfZeros;
        }
    }

    if (currentNumberOfZeros != 0) {
        maxDistance = std::max(maxDistance, currentNumberOfZeros);
    }

    return maxDistance;
}
