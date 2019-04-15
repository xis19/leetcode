#include <functional>
#include <unordered_map>
#include <vector>

int pathSum(const std::vector<int>& nums) {
    std::unordered_map<int, std::unordered_map<int, int>> tree;
    for(auto n: nums) {
        int D = n / 100;
        int P = n / 10 % 10;
        int V = n % 10;
        tree[D][P] = V;
    }

    int sum(0);
    std::function<bool(int, int, int)> traverse =
            [&tree, &traverse, &sum](int r, int c, int s) -> bool {
        if (tree.find(r) == tree.end()) return false;
        if (tree[r].find(c) == tree[r].end()) return false;
        s = s + tree[r][c];
        bool left = traverse(r + 1, c * 2 - 1, s);
        bool right = traverse(r + 1, c * 2, s);
        if (!left && !right) {
            sum += s;
        }
        return true;
    };

    traverse(1, 1, 0);
    return sum;
}
