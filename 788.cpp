#include <string>


int rotatedDigits(const int N) {
    int count(0);
    for(int i = 1; i <= N; ++i) {
        std::string s = std::to_string(i);
        bool valid = true;
        for(auto& ch: s) {
            switch(ch) {
                case '2':
                    ch = '5';
                    break;
                case '5':
                    ch = '2';
                    break;
                case '6':
                    ch = '9';
                    break;
                case '9':
                    ch = '6';
                    break;
                case '3':
                case '4':
                case '7':
                    valid = false;
                    break;
            }
        }
        if (!valid) continue;
        if (std::stoi(s) != i) ++count;
    }
    return count;
}
