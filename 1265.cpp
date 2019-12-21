class ImmutableListNode {
public:
    void printValue(); // print the value of the node.
    ImmutableListNode* getNext(); // return the next node.
};

void printLinkedListInReverse(ImmutableListNode* head) {
    if (head == nullptr) {
        return;
    }
    printLinkedListInReverse(head->getNext());
    head->printValue();
}
