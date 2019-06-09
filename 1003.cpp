// There are two approaches,
// The first approach, you remove "abc" repeatly until you get either an empty
// string, which means the word is valid; or get a non-empty string without abc
// which means the word is not valid.
// Another approach is to use a stack, pop abc repeatly.

#include <vector>
#include <string>

bool isValid(const std::string& S) {
    std::vector<char> chStack;
    int size = 0;
    for(auto ch: S) {
        chStack.push_back(ch);
        ++size;

        if (size >= 3) {
            if (chStack[size - 1] == 'c' && chStack[size - 2] == 'b' &&
                    chStack[size - 3] == 'a') {
                size -= 3;
                chStack.pop_back();
                chStack.pop_back();
                chStack.pop_back();
            }
        }
    }
    return chStack.empty();
}

