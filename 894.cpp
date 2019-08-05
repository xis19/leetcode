#include <functional>
#include <unordered_map>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

std::vector<TreeNode*> allPossibleFBT(int N) {
    std::unordered_map<int, std::vector<TreeNode*>> nodes;

    std::function<std::vector<TreeNode*>&(int)> generate = [&generate, &nodes](int n) -> std::vector<TreeNode*>& {
        if (nodes.find(n) != nodes.end()) return nodes[n];

        if (n == 0) {
            nodes.emplace(0, std::vector<TreeNode*>{});
        } else if (n == 1) {
            nodes.emplace(1, std::vector<TreeNode*>{new TreeNode(0)});
        } else {
            std::vector<TreeNode*> r;
            for(int i = 0; i <= n - 1; ++i) {
                // i is the number of elements on the left side
                auto& lhs = generate(i);
                auto& rhs = generate(n - 1 - i);
                for(auto x: lhs) {
                    for(auto y: rhs) {
                        r.push_back(new TreeNode(0));
                        r.back()->left = x;
                        r.back()->right = y;
                    }
                }
            }
            nodes.emplace(n, r);
        }

        return nodes[n];
    };

    generate(N);

    return nodes[N];
}
