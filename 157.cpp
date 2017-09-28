#include <string>

int read4(char*);

class Solution {
    std::string buffer;
public:
    Solution() : buffer("") {
    }

    int read(char* buf, int n) {
        while(buffer.size() < n) {
            char buf4[5];
            int nbitsRead = read4(buf4);
            if (nbitsRead == 0)
                break;
            buf4[nbitsRead] = 0;
            buffer += buf4;
        }
        n = std::min(static_cast<size_t>(n), buffer.size());
        // \0
        strncpy(buf, buffer.c_str(), n + 1);
        std::string remaining(buffer.c_str() + n);
        std::swap(remaining, buffer);
        return n;
    }
};
