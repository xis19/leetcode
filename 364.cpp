#include <functional>
#include <vector>

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
    public:
        // Constructor initializes an empty nested list.
        NestedInteger();

        // Constructor initializes a single integer.
        NestedInteger(int value);

        // Return true if this NestedInteger holds a single integer, rather than a nested list.
        bool isInteger() const;

        // Return the single integer that this NestedInteger holds, if it holds a single integer
        // The result is undefined if this NestedInteger holds a nested list
        int getInteger() const;

        // Set this NestedInteger to hold a single integer.
        void setInteger(int value);

        // Set this NestedInteger to hold a nested list and adds a nested integer to it.
        void add(const NestedInteger &ni);

        // Return the nested list that this NestedInteger holds, if it holds a nested list
        // The result is undefined if this NestedInteger holds a single integer
        const std::vector<NestedInteger> &getList() const;
};


int depthSumInverse(std::vector<NestedInteger>& nestedList) {
    // We sum per level, then multiply by depth level.
    std::vector<int> depthRecord;
    std::function<void(int, const NestedInteger&)> sumDepth = [&sumDepth, &depthRecord](size_t currentDepth, const NestedInteger& integer) {
        if (depthRecord.size() <= currentDepth) depthRecord.push_back(0);
        if (integer.isInteger()) {
            depthRecord[currentDepth] += integer.getInteger();
        } else {
            for(const auto& item: integer.getList()) {
                sumDepth(currentDepth + 1, item);
            }
        }
    };
    for(const auto& item: nestedList) {
        sumDepth(0, item);
    }
    int result(0);
    for(size_t i = 0; i < depthRecord.size(); ++i) {
        result += (depthRecord.size() - i) * depthRecord[i];
    }
    return result;
}
