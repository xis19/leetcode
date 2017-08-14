struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};


ListNode* deleteDuplicates(ListNode* head) {
    ListNode* iter = head;
    while(iter != nullptr) {
        while(iter->next != nullptr && iter->next->val == iter->val) {
            ListNode* tmp = iter->next;
            iter->next = tmp->next;
            delete tmp;
        }
        iter = iter->next;
    }
    return head;
}
