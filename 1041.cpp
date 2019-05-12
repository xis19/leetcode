#include <string>

const int DIRECTIONS[][2] = {
    {1, 0}, // N
    {0, 1}, // E
    {-1, 0}, // S
    {0, -1}, // W
};

bool isRobotBounded(const std::string& instructions) {
    int y(0), x(0);
    int dir = 0;
    for(auto ch: instructions) {
        if (ch == 'G') y += DIRECTIONS[dir][0], x += DIRECTIONS[dir][1];
        if (ch == 'L') dir = (dir + 3) % 4;
        if (ch == 'R') dir = (dir + 1) % 4;
    }

    if (y == 0 && x == 0) {
        // moved back to the original position...
        return true;
    }

    // This is slightly nasty, if the direction is N, then one can consider it
    // as a "reset" of the movements; on the other hand, if the direction is
    // not N, in 2/4 rounds, the state would be reset.
    if (dir != 0) return true;

    return false;
}
