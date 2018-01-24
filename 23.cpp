#include <algorithm>
#include <queue>
#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* mergeKLists(const std::vector<ListNode*>& lists) {
    auto compare = [](ListNode* l1, ListNode* l2) -> bool {
        return l1->val > l2->val;
    };
    std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(compare)> queue(compare);

    // Add each list to queue
    for(auto n: lists) {
        if (n) queue.push(n);
    }

    // New list
    // we add a head to the result to make list extension easier.
    ListNode* result = new ListNode(0);
    ListNode* last = result;

    while(queue.size() != 0) {
        ListNode* node = queue.top();
        last->next = node;
        node = node->next;
        last = last->next;
        queue.pop();
        if (node)
            queue.push(node);
    }

    // MEMORY LEAK!
    return result->next;
}
