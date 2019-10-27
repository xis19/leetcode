#include <algorithm>
#include <vector>

std::vector<int> pathInZigZagTree(int label) {
    // We treat the tree as a normal tree, and calculate the path, then we flip
    // if necessary
    auto flip = [](int depth, int i) -> int {
        // Note in a row, 2 <> 3, 4 <> 7, 5 <> 6, 8 <> 15, ...
        // We keep the highest bit and flip all other bits
        const int MASK = (1 << (depth - 1)) - 1;
        return i ^ MASK;
    };

    // Calculate the depth of the tree for the label
    // Note it does not matter the order
    int depth = 0;
    {
        int l = label;
        while (l) {
            l >>= 1;
            ++depth;
        }
    }

    if (depth % 2 == 0) {
        // we are in a mirrored row, for ease we flip
        label = flip(depth, label);
    }

    std::vector<int> result;
    for (int i = depth; i >= 1; --i) {
        result.push_back(label);
        label /= 2;
    }

    std::reverse(result.begin(), result.end());
    for (int i = 0; i < depth; ++i) {
        if (i % 2 == 1) {
            result[i] = flip(i + 1, result[i]);
        }
    }

    return result;
}
