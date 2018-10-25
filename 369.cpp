#include <functional>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};


ListNode* plusOne(ListNode* head) {
    std::function<int(ListNode*)> plus = [&](ListNode* n) {
        int res = 1;
        if (n->next) {
            res = plus(n->next);
        }
        n->val += res;
        int ret = n->val / 10;
        n->val %= 10;
        return ret;
    };

    int residue = plus(head);
    if (residue == 1) {
        auto* n = new ListNode(1);
        n->next = head;
        return n;
    }
    return head;
}
