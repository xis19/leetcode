#include <functional>
#include <utility>

class Node {
public:
    int val = 0;
    Node* prev = nullptr;
    Node* next = nullptr;
    Node* child = nullptr;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};


Node* flatten(Node* head) {
        std::function<std::pair<Node*, Node*>(Node*)> flattenLinkList = [&flattenLinkList](Node* start) -> std::pair<Node*, Node*>  {
        Node* iter = start;
        while(true) {
            if (iter->next == nullptr) {
                if (iter->child) {
                    auto childChain = flattenLinkList(iter->child);

                    iter->child = nullptr;

                    childChain.second->next = nullptr;
                    childChain.first->prev = iter;
                    iter->next = childChain.first;
                    iter = childChain.second;
                } else {
                    break;
                }
            } else {
                if (iter->child) {
                    auto childChain = flattenLinkList(iter->child);

                    iter->child = nullptr;

                    iter->next->prev = childChain.second;
                    childChain.second->next = iter->next;
                    iter->next = childChain.first;
                    childChain.first->prev = iter;
                    iter = childChain.second;
                } else {
                    iter = iter->next;
                }
            }
        }

        return std::make_pair(start, iter);
    };

    if (!head) return head;
    return flattenLinkList(head).first;
}
