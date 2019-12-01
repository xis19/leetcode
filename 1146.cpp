#include <map>
#include <vector>

class SnapshotArray {
    std::vector<std::map<int, int>> snapshotArray;
    int snapId = 0;
public:
    SnapshotArray(int length) : snapshotArray(length) {}

    void set(int index, int val) {
        snapshotArray[index][snapId] = val;
    }

    int snap() {
        return snapId++;
    }

    int get(int index, int snapId) {
        if (snapshotArray[index].empty()) {
            return 0;
        }
        auto lBound = snapshotArray[index].lower_bound(snapId);
        if (lBound == snapshotArray[index].end()) {
            return std::prev(lBound)->second;
        }

        if (lBound->first == snapId) {
            return lBound->second;
        }

        if (lBound == snapshotArray[index].begin()) {
            return 0;
        }

        auto prev = std::prev(lBound);
        return prev->second;
    }
};
