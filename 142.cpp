struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *detectCycle(ListNode *head) {
    // We solve it with a fast/slow pointer. If the cycle started at N-th
    // element and the cycle has a perimeter of M.
    //
    // 1. They will meet in the cycle. The fast pointer will visit M nodes more
    // than the slow pointer.
    //
    // 2. If the slow pointer is current at (N + s)-th node, then the fast
    // pointer has visited (N + s + xM) elements, where x is an integer.
    //
    // 3. 2 * (N + s) = (N + s + xM) so N + s = xM or N = xM - s
    //
    // 4. In this case, if we move the slow pointer by xM - s, it would reach
    // the beginning of the cycle. However we do not know s. In this case, we
    // use a new pointer start at head, move it by N, and the slow pointer will
    // move by xM - s. They will meet at the beginning of the cycle.
    if (head == nullptr) return nullptr;

    ListNode* slow = head;
    ListNode* fast = head;
    while(true) {
        fast = fast->next;
        if (fast == nullptr) return nullptr;
        slow = slow->next;
        fast = fast->next;
        if (fast == nullptr) return nullptr;

        if (slow == fast) break;
    }

    ListNode* result = head;
    while(result != slow) {
        result = result->next;
        slow = slow->next;
    }
    return result;
}
