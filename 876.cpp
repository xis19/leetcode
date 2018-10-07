struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


ListNode* middleNode(ListNode* head) {
    // Two pointers, fast and slow
    ListNode* fast = head;
    ListNode* slow = head;

    while(fast != nullptr) {
        fast = fast->next;
        if (fast == nullptr) break;

        slow = slow->next;

        fast = fast->next;
    }

    return slow;
}
