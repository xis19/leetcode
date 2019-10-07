#include <unordered_set>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


int numComponents(ListNode* head, const std::vector<int>& G) {
    std::unordered_set<int> s(G.begin(), G.end());
    int nC(0);  // num components
    bool isInComponent = false;

    while (head != nullptr) {
        if (s.find(head->val) != s.end()) {
            if (!isInComponent) ++nC;   // new component
            isInComponent = true;
        } else {
            isInComponent = false;
        }
        head = head->next;
    }

    return nC;
}
