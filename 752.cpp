#include <array>
#include <functional>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>


int openLock(std::vector<std::string>& deadends, const std::string& target) {
    const std::array<char, 10> NEXT{
        '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'
    };

    const std::unordered_set<std::string> DEADENDS(deadends.begin(), deadends.end());

    // CORNER CASE: "0000" is one of deadends!
    if (DEADENDS.find("0000") != DEADENDS.end()) return -1;

    // Typical BFS -- BFS will always find the shortest path while DFS requires
    // visiting the whole search space.
    std::unordered_set<std::string> visited;

    std::queue<std::pair<int, std::string>> queue;
    queue.push(std::make_pair(0, std::string("0000")));
    visited.insert(queue.front().second);
    while(!queue.empty()) {
        auto v = queue.front();
        queue.pop();

        if (v.second == target) {
            return v.first;
        }

        for(int i = 0; i < 4; ++i) {
            // next
            v.second[i] = NEXT[v.second[i] - '0'];
            if (visited.find(v.second) == visited.end() &&
                    DEADENDS.find(v.second) == DEADENDS.end()) {
                queue.push(std::make_pair(v.first + 1, v.second));
                visited.insert(v.second);
            }

            // prev, note the NEXT operation is cyclic
            v.second[i] = NEXT[(v.second[i] - '0' + 7) % 10];
            if (visited.find(v.second) == visited.end() &&
                    DEADENDS.find(v.second) == DEADENDS.end()) {
                queue.push(std::make_pair(v.first + 1, v.second));
                visited.insert(v.second);
            }

            // Reset
            v.second[i] = NEXT[v.second[i] - '0'];
        }
    }

    return -1;
}
