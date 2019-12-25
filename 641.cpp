#include <vector>

class MyCircularDeque {
    const int maxLength;
    std::vector<int> container;
    int length = 0;
    int start = 0, end = 0;
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k): maxLength(k), container(k, 0) {
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (length == maxLength) {
            return false;
        }
        if (start == 0) {
            start = maxLength;
        }
        ++length;
        container[--start] = value;
        return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (length == maxLength) {
            return false;
        }
        if (end == maxLength) {
            end = 0;
        }
        ++length;
        container[end++] = value;
        return true;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (length == 0) {
            return false;
        }
        --length;
        if (++start == maxLength) {
            start = 0;
        }
        return true;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (length == 0) {
            return false;
        }
        --length;
        // Note the order of --end and end == 0 cnanot be changed.
        //
        // Consider start = maxLength - 1, and end = 0 situation.
        // this can be reached by do an insertFront when the queue is empty
        if (end == 0) {
            end = maxLength;
        }
        --end;
        return true;
    }

    /** Get the front item from the deque. */
    int getFront() {
        if (length == 0) return -1;
        return container[start];
    }

    /** Get the last item from the deque. */
    int getRear() {
        if (length == 0) return -1;
        if (end == 0) {
            return container[maxLength - 1];
        }
        return container[end - 1];
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return length == 0;
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return length == maxLength;
    }
};
