#include <unordered_map>
#include <unordered_set>
#include <vector>

int robotSim(const std::vector<int>& commands, const std::vector<std::vector<int>>& obstacles) {
    const int DIRMAP[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    int x(0), y(0);
    int dX = 0, dY = 1;
    int direction = 0;

    std::unordered_map<int, std::unordered_set<int>> obstaclesSet;
    for(auto& obstacle: obstacles) {
        obstaclesSet[obstacle[0]].insert(obstacle[1]);
    }

    int maxDistance = 0;
    for(auto command: commands) {
        if (command > 0) {
            for(int i = 0; i < command; ++i) {
                int newX = x + dX, newY = y + dY;
                auto set = obstaclesSet.find(newX);
                if (set != obstaclesSet.end() && set->second.find(newY) != set->second.end()) break;
                x = newX;
                y = newY;
                maxDistance = std::max(x * x + y * y, maxDistance);
            }
        } else if (command == -1) {
            // clockwise
            direction += 1;
            direction %= 4;
            dX = DIRMAP[direction][0];
            dY = DIRMAP[direction][1];
        } else if (command == -2) {
            // anti-clockwise
            direction -= 1;
            if (direction < 0) direction = 3;
            dX = DIRMAP[direction][0];
            dY = DIRMAP[direction][1];
        }
    }

    return maxDistance;
}
