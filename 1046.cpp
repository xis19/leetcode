#include <queue>
#include <vector>

int lastStoneWeight(const std::vector<int>& stones) {
    std::priority_queue<int> stoneHeap;
    for(auto s: stones) stoneHeap.push(s);

    while(stoneHeap.size() > 1) {
        int y = stoneHeap.top();
        stoneHeap.pop();
        int x = stoneHeap.top();
        stoneHeap.pop();

        if (y > x) stoneHeap.push(y - x);
    }

    return stoneHeap.top();
}
