#include <stack>

int binaryGap(int N) {
    std::stack<int> s;

    int index = 0;
    while(N) {
        if ((N & 1) == 1) s.push(index);
        N >>= 1;
        ++index;
    }

    if (s.empty()) return 0;
    int lastIndex = s.top();
    s.pop();

    int maxLen = 0;
    while(!s.empty()) {
        maxLen = std::max(maxLen, lastIndex - s.top());
        lastIndex = s.top();
        s.pop();
    }

    return maxLen;
}
