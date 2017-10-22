#include <queue>
#include <tuple>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


int widthOfBinaryTree(TreeNode* root) {
    if (!root) return 0;

    std::queue<std::tuple<TreeNode*, int, int>> visitors;
    visitors.push(std::make_tuple(root, 0, 0));
    int level(0), min(0), max(0), maxWidth(0);
    while(!visitors.empty()) {
        auto item = visitors.front();
        visitors.pop();

        auto node = std::get<0>(item);
        auto nodeLevel = std::get<1>(item);
        auto nodeIndex = std::get<2>(item);
        if (node->left) {
            visitors.push(std::make_tuple(node->left, nodeLevel + 1, nodeIndex * 2));
        }
        if (node->right) {
            visitors.push(std::make_tuple(node->right, nodeLevel + 1, nodeIndex * 2 + 1));
        }
        if (level != nodeLevel) {
            min = nodeIndex;
            max = nodeIndex;
            level = nodeLevel;
        } else {
            min = std::min(min, nodeIndex);
            max = std::max(max, nodeIndex);
        }
        maxWidth = std::max(maxWidth, max - min + 1);
    }
    return maxWidth;
}
