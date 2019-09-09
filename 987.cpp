#include <algorithm>
#include <functional>
#include <unordered_map>
#include <utility>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

std::vector<std::vector<int>> verticalTraversal(TreeNode* root) {
    // key: vertical index; value: <horizontal index, value>
    std::unordered_map<int, std::vector<std::pair<int, int>>> data;
    std::function<void(TreeNode*, int, int)> traverse =
            [&data, &traverse](TreeNode* node, int x, int y) {
        if (node == nullptr) {
            return;
        }

        data[x].push_back(std::make_pair(y, node->val));

        traverse(node->left, x - 1, y + 1);
        traverse(node->right, x + 1, y + 1);
    };

    traverse(root, 0, 0);

    int minIndex(0), maxIndex(0);
    for(auto& result: data) {
        std::sort(result.second.begin(), result.second.end(),
                  [](const std::pair<int, int>& r1,
                     const std::pair<int, int>& r2) {
            if (r1.first != r2.first) {
                return r1.first < r2.first;
            }
            return r1.second < r2.second;
        });
        minIndex = std::min(minIndex, result.first);
        maxIndex = std::max(maxIndex, result.first);
    }

    std::vector<std::vector<int>> result;
    for (int i = minIndex; i <= maxIndex; ++i) {
        result.emplace_back(std::vector<int>());
        std::transform(data[i].begin(), data[i].end(),
                       std::back_inserter(result.back()),
                       [](const std::pair<int, int>& r) -> int {
                           return r.second;
                       });
    }

    return result;
};
