struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


ListNode* oddEvenList(ListNode* head) {
    ListNode* even = new ListNode(0);
    ListNode* evenIter = even;
    ListNode* odd = new ListNode(0);
    ListNode* oddIter = odd;

    int count(1);
    ListNode* iter = head;
    while(iter != nullptr) {
        if (count & 1) {
            // odd
            oddIter->next = iter;
            oddIter = iter;
            iter = iter->next;
            oddIter->next = nullptr;
        } else {
            // even
            evenIter->next = iter;
            evenIter = iter;
            iter = iter->next;
            evenIter->next = nullptr;
        }
        ++count;
    }

    oddIter->next = even->next;

    delete even;
    delete odd;

    return head;
}
