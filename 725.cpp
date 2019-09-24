#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

std::vector<ListNode*> splitListToParts(ListNode* root, int k) {
    int length = 0;
    {
        auto i = root;
        while(i != nullptr) ++length, i = i->next;
    }

    int blockSize = length / k;
    // E.g. for 9 elements, 5 blocks, first 4 block should have 2 elements;
    // the lsat block should have 1 element.
    int modulus = length % k;

    std::vector<ListNode*> result;
    auto i = root;
    int blockIndex = 0;
    while(i != nullptr) {
        if (blockIndex == 0) {
            result.push_back(i);
        }

        ++blockIndex;
        if (blockIndex == blockSize + (modulus > 0)) {
            // We are finishing one block
            auto tmp = i;
            i = i->next;
            tmp->next = nullptr;

            --modulus;
            blockIndex = 0;
        } else {
            i = i->next;
        }
    }

    while(static_cast<int>(result.size()) < k) result.push_back(nullptr);

    return result;
}
