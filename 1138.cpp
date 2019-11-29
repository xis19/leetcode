#include <string>
#include <unordered_map>
#include <vector>

std::string alphabetBoardPath(const std::string target) {
    const std::unordered_map<char, std::vector<int>> charMap = {
        {'a', {0, 0}},
        {'b', {0, 1}},
        {'c', {0, 2}},
        {'d', {0, 3}},
        {'e', {0, 4}},
        {'f', {1, 0}},
        {'g', {1, 1}},
        {'h', {1, 2}},
        {'i', {1, 3}},
        {'j', {1, 4}},
        {'k', {2, 0}},
        {'l', {2, 1}},
        {'m', {2, 2}},
        {'n', {2, 3}},
        {'o', {2, 4}},
        {'p', {3, 0}},
        {'q', {3, 1}},
        {'r', {3, 2}},
        {'s', {3, 3}},
        {'t', {3, 4}},
        {'u', {4, 0}},
        {'v', {4, 1}},
        {'w', {4, 2}},
        {'x', {4, 3}},
        {'y', {4, 4}},
        {'z', {5, 0}}
    };

    std::string result;
    int x(0), y(0);
    int currCh = 'a';
    for (char ch: target) {
        if (ch != currCh) {
            int newX, newY;
            newX = charMap.at(ch)[1];
            newY = charMap.at(ch)[0];
            char moveChar;
            if (ch == 'z') {
                // If we are moving to 'z', then we must adjust the row then col
                moveChar = newX > x ? 'R' : 'L';
                for (int i = 0; i < std::abs(newX - x); ++i) result.push_back(moveChar);
                moveChar = newY > y ? 'D' : 'U';
                for (int i = 0; i < std::abs(newY - y); ++i) result.push_back(moveChar);
            } else {
                // In case we are moving out from 'z', must first col then row
                moveChar = newY > y ? 'D' : 'U';
                for (int i = 0; i < std::abs(newY - y); ++i) result.push_back(moveChar);
                moveChar = newX > x ? 'R' : 'L';
                for (int i = 0; i < std::abs(newX - x); ++i) result.push_back(moveChar);
            }
            y = newY;
            x = newX;
            currCh = ch;
        }
        result.push_back('!');
    }

    return result;
}
