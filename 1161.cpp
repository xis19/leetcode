#include <functional>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int maxLevelSumFast(TreeNode* root) {
    std::vector<int> sumMap;
    std::function<void(size_t, TreeNode*)> traverse = [&sumMap, &traverse](size_t depth, TreeNode* node) {
        if (sumMap.size() < depth + 1) sumMap.push_back(0);
        sumMap[depth] += node->val;
        if (node->left != nullptr) traverse(depth + 1, node->left);
        if (node->right != nullptr) traverse(depth + 1, node->right);
    };
    traverse(0, root);

    int max = sumMap[0];
    int maxIndex = 0;
    for (int i = 0; i < static_cast<int>(sumMap.size()); ++i) {
        if (sumMap[i] > max) {
            max = sumMap[i];
            maxIndex = i;
        }
    }

    return maxIndex + 1;
}

int maxLevelSum(TreeNode* root) {
    std::queue<std::pair<int, TreeNode*>> visitQueue;
    visitQueue.push(std::make_pair(1, root));

    std::unordered_map<int, int> sumMap;

    while (!visitQueue.empty()) {
        auto front = visitQueue.front();
        visitQueue.pop();

        if (sumMap.find(front.first) == sumMap.end()) {
            sumMap[front.first] = 0;
        }
        sumMap[front.first] += front.second->val;

        if (front.second->left != nullptr) {
            visitQueue.push(std::make_pair(front.first + 1, front.second->left));
        }
        if (front.second->right!= nullptr) {
            visitQueue.push(std::make_pair(front.first + 1, front.second->right));
        }
    }

    int max = sumMap[1];
    int result = 1;
    int i = 2;
    while (sumMap.find(i) != sumMap.end()) {
        if (sumMap[i] > max) {
            result = i;
            max = sumMap[i];
        }
        ++i;
    }

    return result;
}

