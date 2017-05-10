struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    auto listLen = [](ListNode* i) -> int {
        int c = 0;
        while(i) ++c, i = i->next;
        return c;
    };
    int lenA = listLen(headA);
    int lenB = listLen(headB);

    if (lenA < lenB) {
        std::swap(lenA, lenB);
        std::swap(headA, headB);
    }

    int diff = lenA - lenB;
    for(int i = 0; i < diff; ++i) headA = headA->next;

    while(headA && headA != headB) {
        headA = headA->next;
        headB = headB->next;
    }

    return headA;
}
