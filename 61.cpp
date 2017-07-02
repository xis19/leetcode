struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// This strategy is not sufficient when k is huge.
ListNode* rotateRightSlow(ListNode* head, int k) {
    // Corner case: Empty input
    if (head == nullptr) return nullptr;
    if (k == 0) return head;

    ListNode* newTail = head;
    ListNode* oldTail = head;

    for(int i = 0; i < k; ++i) {
        // Corner case: List length is less than k
        oldTail = oldTail->next ? oldTail->next : head;
    }

    while(oldTail->next) {
        oldTail = oldTail->next;
        newTail = newTail->next;
    }

    // Corner case: new tail is the old tail
    if (newTail->next == nullptr)
        return head;
    ListNode* newHead = newTail->next;
    newTail->next = nullptr;
    oldTail->next = head;

    return newHead;
}

ListNode* rotateRight(ListNode* head, int k) {
    // Corner case: Empty input
    if (head == nullptr) return nullptr;

    // Corner case: when k is huge
    int LEN = 0;
    ListNode* iter = head;
    while(iter) ++LEN, iter = iter->next;

    k = k % LEN;

    ListNode* newTail = head;
    ListNode* oldTail = head;

    for(int i = 0; i < k; ++i) {
        // Corner case: List length is less than k
        oldTail = oldTail->next ? oldTail->next : head;
    }

    while(oldTail->next) {
        oldTail = oldTail->next;
        newTail = newTail->next;
    }

    // Corner case: new tail is the old tail
    if (newTail->next == nullptr)
        return head;
    ListNode* newHead = newTail->next;
    newTail->next = nullptr;
    oldTail->next = head;

    return newHead;

}
