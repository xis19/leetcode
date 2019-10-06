#include <sstream>
#include <string>
#include <vector>

std::vector<std::string> removeComments(std::vector<std::string>& source) {
    bool isInQuotes(false), isInScopeComment(false), isInLineComment(false);

    std::stringstream ss;
    for (auto& line: source) {
        ss << line << std::endl;
    }

    std::stringstream os;
    char ch;
    while(ss.get(ch)) {
        if (isInQuotes) {
            os << ch;
            if (ch == '"') isInQuotes = false;
        } else if (isInLineComment) {
            if (ch == '\n') {
                os << ch;
                isInLineComment = false;
            }
        } else if (isInScopeComment) {
            if (ch == '*') {
                char lookAhead = ss.get();
                if (lookAhead == '/') {
                    isInScopeComment = false;
                } else {
                    ss.unget();
                }
            }
        } else {
            if (ch == '"') {
                os << ch;
                isInQuotes = true;
            } else if (ch == '/') {
                char lookAhead = ss.get();
                if (lookAhead == '*') {
                    isInScopeComment = true;
                } else if (lookAhead == '/') {
                    isInLineComment = true;
                } else {
                    ss.unget();
                    os << ch;
                }
            } else {
                os << ch;
            }
        }
    }

    std::vector<std::string> result;
    std::string line;
    while(std::getline(os, line)) {
        if (line.size() != 0) result.emplace_back(line);
    }

    return result;
}
