#include <queue>
#include <utility>
#include <vector>

const int INF = 2147483647;
const int WALL = -1;
const int GATE = 0;

void wallsAndGates(std::vector<std::vector<int>>& rooms) {
    const int NROWS = rooms.size();
    if (NROWS == 0) return;
    const int NCOLS = rooms[0].size();
    if (NCOLS == 0) return;

    // First we find all gates
    std::vector<std::pair<int, int>> gates;
    for(int i = 0; i < NROWS; ++i) {
        for(int j = 0; j < NCOLS; ++j) {
            if (rooms[i][j] == GATE) {
                gates.push_back(std::make_pair(i, j));
            }
        }
    }

    // Now we do a BFS per gate
    // First part is the cursor, second part is the distance
    std::queue<std::pair<std::pair<int, int>, int>> bfs;
    for(const auto& gate: gates) {
        bfs.push(std::make_pair(gate, 0));
        while(!bfs.empty()) {
            auto _ = bfs.front();
            auto cursor = _.first;
            auto distance = _.second;
            bfs.pop();

            rooms[cursor.first][cursor.second] = distance;

            const int nextDistance = distance + 1;

            // Explore surrounds
            if (cursor.first > 0 && rooms[cursor.first - 1][cursor.second] > nextDistance) {
                bfs.push(std::make_pair(std::make_pair(cursor.first - 1, cursor.second), nextDistance));
            }
            if (cursor.second > 0 && rooms[cursor.first][cursor.second - 1] > nextDistance) {
                bfs.push(std::make_pair(std::make_pair(cursor.first, cursor.second - 1), nextDistance));
            }
            if (cursor.first < NROWS - 1 && rooms[cursor.first + 1][cursor.second] > nextDistance) {
                bfs.push(std::make_pair(std::make_pair(cursor.first + 1, cursor.second), nextDistance));
            }
            if (cursor.second < NCOLS - 1 && rooms[cursor.first][cursor.second + 1] > nextDistance) {
                bfs.push(std::make_pair(std::make_pair(cursor.first, cursor.second + 1), nextDistance));
            }
        }
    }
}
