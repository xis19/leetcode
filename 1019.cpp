#include <stack>
#include <utility>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

std::vector<int> nextLargerNodes(ListNode* head) {
    // First item is the value, second item is the index in the result
    std::stack<std::pair<int, int>> stack;
    std::vector<int> result;

    while(head != nullptr) {
        result.push_back(0);
        const int value = head->val;
        while (!stack.empty() && stack.top().first < value) {
            result[stack.top().second] = value;
            stack.pop();
        }
        stack.push(std::make_pair(value, result.size() - 1));
        head = head->next;
    }

    return result;
}
