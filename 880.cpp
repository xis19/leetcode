#include <string>
#include <vector>

std::string decodeAtIndex(const std::string& S, int K) {
    // We consider, e.g. A2B3
    // it would be AABAABAAB
    // When we see a characer, we record its index of generated string so far
    // when we see a number, we record the length of the string cycle.
    //  A 3 B 5
    //  1 3 4 4
    // E.g.
    //  l  e  e  t  2  c  o  d  e  3
    //  1  2  3  4  4  9 10 11 12 12
    enum type_t { CHAR, NUMBER };
    typedef struct {
        type_t type;
        char value;
        long record;
    } record_t;
    std::vector<record_t> rec;
    long cycleLen = 0;
    for (auto ch: S) {
        if ('0' <= ch && ch <= '9') {
            char v = ch - '0';
            rec.push_back(record_t{NUMBER, v, cycleLen});
            cycleLen *= v;
        } else {
            ++cycleLen;
            rec.push_back(record_t{CHAR, ch, cycleLen});
        }
    }

    // We roll back --
    //  if it is a cycle, then modulus. NOTE!! if modulus == 0, then it means
    //  the character is at the end of the cycle, so the new K would be the
    //  length of the cycle.
    //  if it is a character, then check if it has the right index;
    for (auto rIter = rec.rbegin(); rIter != rec.rend(); ++rIter) {
        if (rIter->type == NUMBER) {
            K %= rIter->record;
            if (K == 0) {
                K = rIter->record;
            }
        } else {
            if (K == rIter->record) {
                return std::string() + rIter->value;
            }
        }
    }

    return std::string();
}
