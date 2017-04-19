#include <iterator>
#include <string>

std::string reverseWords(std::string input) {
    const int LEN = input.length();

    auto reverseRange = [&](int start, int end) -> void {
        --end;
        while(start <  end) {
            std::swap(input[start], input[end]);
            ++start, --end;
        }
    };

    int last = 0;
    for(int i = 0; i < LEN; ++i) {
        char ch = input[i];
        if (ch != ' ') {
            continue;
        }
        reverseRange(last, i);
        last = i + 1;
    }
    reverseRange(last, LEN);
    return input;
}

#include <iostream>
int main() {
    std::cout << reverseWords("Hello, world!") << std::endl;
    std::cout << reverseWords("Hello,") << std::endl;
    std::cout << reverseWords("") << std::endl;

    return 0;
}

