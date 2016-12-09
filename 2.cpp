struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* head = nullptr;
    ListNode* current = nullptr;
    bool carry(false);   // carry bit

    while(l1 || l2) {
        int value = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
        carry = (value >= 10);
        value = value % 10;

        ListNode* newNode = new ListNode(value);
        if (!head)
            head = current = newNode;
        else {
            current->next = newNode;
            current = newNode;
        }

        l1 = l1 ? l1->next : nullptr;
        l2 = l2 ? l2->next : nullptr;
    }

    if (carry)
        current->next = new ListNode(1);

    return head;
}
