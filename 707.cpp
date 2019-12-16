class MyLinkedList {
    struct LinkedList {
        int value;
        LinkedList* next;
        LinkedList(int v): value(v), next(nullptr) {}
    };

    LinkedList head;
    LinkedList* tail;
public:
    MyLinkedList(): head(0){
        tail = &head;
    }

    int get(int index) {
        auto h = &head;
        for (int i = 0; i <= index; ++i) {
            if (h == nullptr) {
                return -1;
            }
            h = h->next;
        }
        return h == nullptr ? -1 : h->value;
    }

    void addAtHead(int val) {
        LinkedList* n = new LinkedList(val);
        n->next = head.next;
        head.next = n;
    }

    void addAtTail(int val) {
        auto h = &head;
        while(h->next != nullptr) h = h->next;
        h->next = new LinkedList(val);
    }

    void addAtIndex(int index, int val) {
        auto h = &head;
        for (int i = 0; i <= index - 1; ++i) {
            if (h == nullptr) return;
            h = h->next;
        }
        LinkedList* n = new LinkedList(val);
        n->next = h->next;
        h->next = n;
    }

    void deleteAtIndex(int index) {
        auto h = &head;
        for (int i = 0; i <= index - 1; ++i) {
            if (h == nullptr) return;
            h = h->next;
        }
        if (h->next == nullptr) return;
        LinkedList* l = h->next;
        h->next = l->next;
        delete l;
    }
};
