#include <string>
#include <stack>

bool isValid(const std::string& s) {
    std::stack<char> ops;
    for(auto ch : s) {
        if (ch == '{' || ch == '[' || ch == '(') {
            ops.push(ch);
        } else {
            if (ops.empty()) {
                return false;
            }

            char top = ops.top();
            if ((ch == '}' && top == '{') || (ch == ']' && top == '[') || (ch == ')' && top == '(')) {
                ops.pop();
            } else {
                return false;
            }
        }
    }
    return ops.empty();
}
