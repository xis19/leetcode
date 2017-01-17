#include <stack>
#include <string>
#include <vector>

//                    0123456789ABCDE
// Input              ()()(()))(()()(
// Unpaired ( Count   x0x2xx45-xxAxCx
// The first run we find all unpaired ( and ). The second run we find the
// longest length without any unpaired ( and ).

int longestValidParentheses(const std::string& s) {
    const int UNPAIRED = -1;
    const int LEN = s.size();
    std::vector<int> pairing(LEN, UNPAIRED);
    std::stack<int> lParentheses;

    for(int i = 0; i < LEN; ++i) {
        if (s[i] == '(') {
            lParentheses.push(i);
        } else if (!lParentheses.empty()) {
            int last = lParentheses.top();
            pairing[i] = last;
            pairing[last] = i;
            lParentheses.pop();
        }
    }

    int maxLength = 0, currentLength = 0;
    for(auto i: pairing) {
        if (i != UNPAIRED) {
            ++currentLength;
        } else {
            maxLength = std::max(maxLength, currentLength);
            currentLength = 0;
        }
    }
    return std::max(maxLength, currentLength);
}
