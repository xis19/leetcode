#include <functional>
#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


TreeNode* sortedListToBST(ListNode* head) {
    if (!head) return nullptr;

    int listLength(0);
    auto iter = head;
    while(iter) {
        ++listLength;
        iter = iter->next;
    }

    std::vector<TreeNode*> nodes(listLength);
    iter = head;
    for(int i = 0; i < listLength; ++i, iter = iter->next) {
        nodes[i] = new TreeNode(iter->val);
    }

    std::function<TreeNode*(int, int)> construct = [&construct, &nodes](int lo, int hi) -> TreeNode*{
        int mid = lo + (hi - lo) / 2;
        nodes[mid]->left = mid > lo ? construct(lo, mid) : nullptr;
        nodes[mid]->right = mid < hi - 1 ? construct(mid + 1, hi) : nullptr;
        return nodes[mid];
    };

    return construct(0, listLength);
}
