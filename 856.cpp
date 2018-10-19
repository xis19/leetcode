#include <stack>
#include <string>


int scoreOfParentheses(const std::string& S) {
    std::stack<int> s;
    for(auto ch: S) {
        if (ch == '(') {
            s.push(-1);
        } else {
            if (s.top() == -1) {
                s.pop();
                s.push(1);
            } else {
                int val = 0;
                while(s.top() != -1) {
                    val += s.top();
                    s.pop();
                }
                s.pop();
                s.push(val * 2);
            }
        }
    }

    int sum = 0;
    while(!s.empty()) {
        sum += s.top();
        s.pop();
    }

    return sum;
}
