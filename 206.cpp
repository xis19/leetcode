#include <functional>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseList(ListNode* head) {
    if (!head) return nullptr;

    ListNode* result = nullptr;

    std::function<ListNode*(ListNode*)> recursive = [&recursive, &result](ListNode* n) -> ListNode* {
        if (n->next == nullptr) {
            result = n;
        } else {
            ListNode* next = recursive(n->next);
            next->next = n;
            n->next = nullptr;
        }
        return n;
    };

    std::function<ListNode*(ListNode*)> iterative = [](ListNode* n) -> ListNode* {
        ListNode* iter = n->next;
        ListNode* prevIter = n;
        n->next = nullptr;
        while(iter != nullptr) {
            auto tmp = iter->next;
            iter->next = prevIter;
            prevIter = iter;
            iter = tmp;
        }
        return prevIter;
    };


    recursive(head);
    return result;
}
