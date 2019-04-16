class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};

Node* insert(Node* head, int insertVal) {
    Node* newNode = new Node();
    newNode->val = insertVal;

    // Special case: empty
    if (head == nullptr) {
        newNode->next = newNode;
        return newNode;
    }

    // Special case: only one element
    if (head->next == head) {
        head->next = newNode;
        newNode->next = head;
        return head;
    }

    // Find the min/max element
    Node* minIter = head->next;
    Node* maxIter = head;
    while(minIter->val >= maxIter->val) {
        maxIter = minIter;
        minIter = minIter->next;

        // Corner case: all elements in the list have same value
        if (maxIter == head) {
            break;
        }
    }

    // Check if new element is smaller than the minimal one
    if (insertVal < minIter->val) {
        maxIter->next = newNode;
        newNode->next = minIter;
        return head;
    }

    // Now we are going to insert the newNode
    Node* insertIter = minIter;
    while(insertIter != maxIter && insertIter->next->val < insertVal) {
        insertIter = insertIter->next;
    }

    newNode->next = insertIter->next;
    insertIter->next = newNode;

    return head;
}
