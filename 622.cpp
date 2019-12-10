#include <vector>

class MyCircularQueue {
    const int SIZE;
    std::vector<int> circularQueue;
    int start, end;
    int numElements;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k): SIZE(k), circularQueue(SIZE), start(0), end(0), numElements(0) { }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (numElements == SIZE) {
            return false;
        }
        end = end % SIZE;
        circularQueue[end] = value;
        ++end;
        ++numElements;
        return true;
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (numElements == 0) {
            return false;
        }
        start += 1;
        if (start == SIZE) {
            start = 0;
        }
        --numElements;
        return true;
    }

    /** Get the front item from the queue. */
    int Front() {
        if (numElements == 0) { return -1; }
        return circularQueue[start];
    }

    /** Get the last item from the queue. */
    int Rear() {
        if (numElements == 0) { return -1; }
        int lastIndex = (end - 1 + SIZE) % SIZE;
        return circularQueue[lastIndex];
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return numElements == 0;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return numElements == SIZE;
    }
};

