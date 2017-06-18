#include <queue>

class MyStack {
    private:
        std::queue<int> q;
    public:
        MyStack() {
        }

        void push(int x) {
            std::queue<int> t;
            while(!q.empty()) {
                t.push(q.front());
                q.pop();
            }
            q.push(x);
            while(!t.empty()) {
                q.push(t.front());
                t.pop();
            }
        }

        int pop() {
            int r = q.front();
            q.pop();
            return r;
        }

        int top() {
            return q.front();
        }

        bool empty() {
            return q.empty();
        }
};
