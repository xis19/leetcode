struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};


ListNode* swapPairs(ListNode* head) {
    ListNode* newHead = new ListNode(0);
    newHead->next = head;

    auto swap = [](ListNode* prehead) -> ListNode* {
        if (prehead == nullptr) return nullptr;
        ListNode* n1 = prehead->next;
        if (n1 == nullptr) return nullptr;
        ListNode* n2 = n1->next;
        if (n2 == nullptr) return nullptr;
        n1->next = n2->next;
        n2->next = n1;
        prehead->next = n2;
        return n1;
    };

    ListNode* prehead = newHead;
    while(prehead) {
        prehead = swap(prehead);
    }

    ListNode* result = newHead->next;
    delete newHead;
    return result;
}
