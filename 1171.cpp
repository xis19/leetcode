#include <utility>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* removeZeroSumSublists(ListNode* head) {
    std::vector<std::pair<int, ListNode*>> history;
    auto iter = head;
    while(iter != nullptr) {
        history.push_back(std::make_pair(iter->val, iter));
        iter = iter->next;

        int sum = 0;
        int sumIter = history.size() - 1;
        for(;sumIter >= 0; --sumIter) {
            sum += history[sumIter].first;
            if (sum == 0) break;
        }
        if (sumIter >= 0) {
            history.resize(sumIter);
            if (sumIter == 0) {
                head = iter;
            } else {
                history.back().second->next = iter;
            }
        }
    }
    return head;
}
