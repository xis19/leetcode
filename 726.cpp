#include <algorithm>
#include <stack>
#include <string>
#include <sstream>
#include <unordered_map>
#include <utility>
#include <vector>

std::string countOfAtoms(const std::string& formula) {
    enum TokenType {
        START, ATOM, COUNT, LPARENTHESIS, RPARENTHESIS, END
    };
    struct Token {
        TokenType type;
        std::string atom = "";
        int count = 0;

        Token(TokenType t): type(t) {}
        Token(TokenType t, std::string&& a): type(t), atom(std::move(a)) {}
        Token(TokenType t, const int c): type(t), count(c) {}
    };

    auto tokenIter = formula.begin();
    const auto endIter = formula.end();
    auto nextToken = [&]() -> Token {
        if (tokenIter == endIter) {
            return Token(END);
        } else if (*tokenIter == '(') {
            ++tokenIter;
            return Token(LPARENTHESIS);
        } else if (*tokenIter == ')') {
            ++tokenIter;
            return Token(RPARENTHESIS);
        } else if (std::isalpha(*tokenIter)) {
            std::string atom;
            atom.push_back(*tokenIter++);
            while(std::islower(*tokenIter) && tokenIter != endIter)
                atom.push_back(*tokenIter++);
            return Token(ATOM, std::move(atom));
        }

        int c = 0;
        while(std::isdigit(*tokenIter) && tokenIter != endIter)
            c = c * 10 + (*tokenIter++ - '0');
        return Token(COUNT, c);
    };
    auto addAtom = [](std::unordered_map<std::string, int>& m,
                      const std::string& atom,
                      const int count) {
        if (m.find(atom) == m.end()) {
            m[atom] = count;
        } else {
            m[atom] += count;
        }
    };
    auto merge = [&addAtom](std::unordered_map<std::string, int>& t,
                    const std::unordered_map<std::string, int>& a) {
        for(const auto c: a) {
            addAtom(t, c.first, c.second);
        }
    };

    std::stack<std::unordered_map<std::string, int>> s;
    s.push(std::unordered_map<std::string, int>());

    Token t(START);
    while(t.type != END) {
        t = nextToken();
        if (t.type == LPARENTHESIS) {
            s.push(std::unordered_map<std::string, int>());
        } else if (t.type == RPARENTHESIS) {
            std::unordered_map<std::string, int> top(s.top());
            s.pop();

            // Prefetch
            auto currentTokenIter = tokenIter;
            auto nToken = nextToken();
            if (nToken.type != COUNT) {
                tokenIter = currentTokenIter;
            } else {
                for(auto& c: top) {
                    c.second *= nToken.count;
                }
            }
            merge(s.top(), top);
        } else if (t.type == ATOM) {
            // Prefetch
            auto currentTokenIter = tokenIter;
            auto nToken = nextToken();
            if (nToken.type != COUNT) {
                addAtom(s.top(), t.atom, 1);
                tokenIter = currentTokenIter;
            } else {
                addAtom(s.top(), t.atom, nToken.count);
            }
        }
    }

    std::vector<std::pair<std::string, int>> sortedAtomList(
            s.top().begin(), s.top().end());
    std::sort(sortedAtomList.begin(), sortedAtomList.end(),
            [](const std::pair<std::string, int>& s1,
               const std::pair<std::string, int>& s2) -> bool {
                return s1.first < s2.first;
            }
    );

    std::stringstream ss;
    for(const auto& s: sortedAtomList) {
        ss << s.first;
        if (s.second > 1) {
            ss << s.second;
        }
    }
    return ss.str();
}
