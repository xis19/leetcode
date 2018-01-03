#include <random>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
    ListNode* m_Head;
    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution;
public:
    Solution(ListNode* head) : distribution(0.0, 1.0){
        m_Head = head;
    }
    int getRandom() {
        ListNode* iter = m_Head;
        int result = iter->val;
        double fcount = 1.0;

        while(iter != nullptr) {
            double r = distribution(generator);
            if (r < 1.0 / fcount) result = iter->val;

            fcount += 1;
            iter = iter->next;
        }
        return result;
    }
};
