struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* removeElements(ListNode* head, int val) {
    ListNode* pseudoHead = new ListNode(0);
    pseudoHead->next = head;

    ListNode* iter = pseudoHead;
    while(iter->next) {
        if (iter->next->val == val) {
            ListNode* tmp = iter->next;
            iter->next = tmp->next;
            delete tmp;
        } else {
            iter = iter->next;
        }
    }

    ListNode* ret = pseudoHead->next;
    delete pseudoHead;
    return ret;
}
