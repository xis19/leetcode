#include <algorithm>
#include <stack>
#include <string>

std::string removeDuplicates(const std::string& S) {
    std::stack<char> chStack;

    for (auto c: S) {
        if (chStack.empty() || chStack.top() != c)
            chStack.push(c);
        else
            chStack.pop();
    }

    std::string result;
    while(!chStack.empty()) {
        result.push_back(chStack.top());
        chStack.pop();
    }

    std::reverse(result.begin(), result.end());

    return result;
}
