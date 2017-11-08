#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <vector>

bool canFinish(int numCourses, const std::vector<std::pair<int, int>>& prerequisites) {
    std::vector<int> visited(numCourses);
    std::fill(visited.begin(), visited.end(), 0);

    std::unordered_map<int, std::vector<int>> edges;
    for(const auto& edge: prerequisites) {
        edges[edge.second].push_back(edge.first);
    }

    std::unordered_set<int> history;
    std::function<bool(int)> check = [&] (int course) {
        if (edges.find(course) == edges.end()) return false;
        if (history.find(course) != history.end()) return true;

        history.insert(course);
        for(auto req: edges[course]) {
            if (check(req))
                return true;
        }
        history.erase(course);
        return false;
    };

    for(int i = 0; i < numCourses; ++i) {
        if (visited[i] == 1) {
            continue;
        }

        visited[i] = 1;
        if (edges.find(i) == edges.end()) {
            // No edge start with it
            continue;
        }

        if (check(i)) {
            // has cycle
            return false;
        }
    }
    return true;
}
