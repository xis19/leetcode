#include <stack>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    std::stack<ListNode*> s1, s2;
    while(l1) { s1.push(l1); l1 = l1->next; }
    while(l2) { s2.push(l2); l2 = l2->next; }

    ListNode* head = new ListNode(0);
    int carry = 0;
    while(s1.empty() + s2.empty() != 2) {
        int v1 = 0, v2 = 0;
        if (!s1.empty()) {
            v1 = s1.top()->val;
            s1.pop();
        }
        if (!s2.empty()) {
            v2 = s2.top()->val;
            s2.pop();
        }

        int val = v1 + v2 + carry;
        head->val = val % 10;
        carry = val / 10;

        ListNode* newHead = new ListNode(0);
        newHead->next = head;
        head = newHead;
    }

    if (carry) {
        head->val = carry;
        return head;
    }

    auto head1 = head->next;
    delete head;
    return head1;
}
