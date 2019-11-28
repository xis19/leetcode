#include <algorithm>
#include <map>
#include <utility>
#include <vector>

std::vector<int> getModifiedArray(int length, const std::vector<std::vector<int>>& updates) {
    // One way is to enumerate all updates and apply it on the result. This will
    // cause timeout.
    // The other way is treat it like Skyline problem, find the start and the
    // end of all ranges and apply them simultaneously. We can use a map and
    // treat it in order.
    std::vector<int> result(length, 0);
    if (updates.size() == 0) return result;

    std::map<int, int> sortedUpdates;
    for (const auto& update: updates) {
        if (sortedUpdates.find(update[0]) == sortedUpdates.end()) {
            sortedUpdates[update[0]] = 0;
        }
        sortedUpdates[update[0]] += update[2];
        if (sortedUpdates.find(update[1] + 1) == sortedUpdates.end()) {
            sortedUpdates[update[1] + 1] = 0;
        }
        sortedUpdates[update[1] + 1] -= update[2];
    }
    sortedUpdates[length] = 0;

    auto iter = sortedUpdates.begin();
    auto value = 0;
    for (int i = 0; i < length; ++i) {
        if (i == iter->first) {
            value += iter->second;
            iter = std::next(iter);
        }
        result[i] = value;
    }
    return result;
}
