#include <limits>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* newHead = new ListNode(0);
    ListNode* newEnd = newHead;

    auto append = [&](ListNode*& item) {
        newEnd->next = item;
        newEnd = item;
        item = item->next;
    };

    while(l1 || l2) {
        if (!l1) {
            append(l2);
        } else if (!l2) {
            append(l1);
        } else {
            append(l1->val < l2->val ? l1 : l2);
        }
    }
    return newHead->next;
}
