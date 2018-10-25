#include <unordered_set>
#include <vector>


int totalFruit(const std::vector<int>& tree) {
    // 保持两个指针，一个指向当前区域，一个指向满足条件的最前一个元素
    const int SIZE = tree.size();

    // Range of the trees to pick up
    int start = 0;

    // Start of latest unique series of tree
    int lastUniqueTreeType = -1;
    int lastUniqueTreeIndex = 0;

    // Current set of tree types
    std::unordered_set<int> currentTreeTypes;

    int longestContinuous = 0;

    for(int end = 0; end < SIZE; ++end) {
        int type = tree[end];

        if (currentTreeTypes.find(type) == currentTreeTypes.end()) {
            if (currentTreeTypes.size() < 2) {
                currentTreeTypes.insert(type);
            } else {
                currentTreeTypes.clear();
                currentTreeTypes.insert(type);
                currentTreeTypes.insert(lastUniqueTreeType);
                start = lastUniqueTreeIndex;
            }
        }

        if (type != lastUniqueTreeType) {
            lastUniqueTreeType = type;
            lastUniqueTreeIndex = end;
        }
        longestContinuous = std::max(longestContinuous, end - start + 1);
    }

    return longestContinuous;
}
