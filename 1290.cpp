struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

int getDecimalValue(ListNode* head) {
    int v = 0;
    while(head != nullptr) {
        v <<= 1;
        v += head->val;
        head = head->next;
    }
    return v;
}

