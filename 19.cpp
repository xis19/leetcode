struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};


ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* lastElementLocator = head;
    for(int i = 0; i < n; ++i) {
        lastElementLocator = lastElementLocator->next;
    }
    if (!lastElementLocator) {
        // We are deleting the first element
        return head->next;
    }

    lastElementLocator = lastElementLocator->next;
    ListNode* elementBeforeRemove = head;
    while(lastElementLocator) {
        elementBeforeRemove = elementBeforeRemove->next;
        lastElementLocator = lastElementLocator->next;
    }
    elementBeforeRemove->next = elementBeforeRemove->next->next;
    return head;
}
