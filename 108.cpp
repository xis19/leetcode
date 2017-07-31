#include <functional>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* sortedArrayToBST(const std::vector<int>& nums) {
    if (nums.size() == 0) return nullptr;

    std::function<TreeNode*(int, int)> generator = [&generator, &nums](int start, int end) -> TreeNode* {
        if (start >= end) {
            return nullptr;
        }
        int mid = start + (end - start) / 2;
        auto result = new TreeNode(nums[mid]);
        result->left = generator(start, mid);
        result->right = generator(mid + 1, end);

        return result;
    };

    return generator(0, nums.size());
}
