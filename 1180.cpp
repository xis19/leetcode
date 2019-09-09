#include <string>

int countLetters(std::string S) {
    S.push_back(' ');

    int sum(0);
    char repCh(0);
    int rep(0);
    for(auto ch: S) {
        if (ch == repCh) {
            ++rep;
        } else {
            repCh = ch;
            sum += (1 + rep) * rep / 2;
            rep = 1;
        }
    }

    return sum;
}
