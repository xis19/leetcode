#include <functional>
#include <vector>

class NestedInteger {
  public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const std::vector<NestedInteger> &getList() const;
};


int depthSum(std::vector<NestedInteger>& nestedList) {
    std::function<int(const std::vector<NestedInteger>&, int)> sum = [&sum](const std::vector<NestedInteger>& items, int depth) -> int {
        int s(0);
        for(const auto& item: items) {
            if (item.isInteger()) {
                s += item.getInteger() * depth;
            } else {
                s += sum(item.getList(), depth + 1);
            }
        }
        return s;
    };

    return sum(nestedList, 1);
}
