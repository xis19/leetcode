#include <algorithm>
#include <deque>
#include <limits>
#include <unordered_map>
#include <unordered_set>
#include <vector>

int minMalwareSpread(const std::vector<std::vector<int>>& graph, std::vector<int>& initial) {
    if (initial.size() == 0) throw std::runtime_error("Error");
    const int VERTICES = graph.size();

    std::sort(initial.begin(), initial.end());

    std::unordered_map<int, std::unordered_set<int>> edges;
    for (int i = 0; i < VERTICES; ++i) {
        for (int j = 0; j < VERTICES; ++j) {
            if (graph[i][j]) edges[i].insert(j);
        }
    }

    // Find all isolated graphes
    std::unordered_set<int> visited;
    std::vector<std::unordered_set<int>> isolated;

    for (int i = 0; i < VERTICES; ++i) {
        if (visited.find(i) != visited.end()) continue;

        isolated.push_back(std::unordered_set<int>());
        std::deque<int> visit;
        visit.push_back(i);
        while (!visit.empty()) {
            auto vertex = visit.front();
            visit.pop_front();

            visited.insert(vertex);
            isolated.back().insert(vertex);

            for (auto i: edges[vertex]) {
                if (visited.find(i) == visited.end()) {
                    visit.push_back(i);
                }
            }
        }
    }

    // Enumerate all isolated graphs, and check those with only one infected
    int maxInfected = std::numeric_limits<int>::min();
    std::vector<int> candidates;
    for (auto iso: isolated) {
        int numInfected(0);
        int infectedNode;
        for (auto inf: initial) {
            if (iso.find(inf) != iso.end()) {
                ++numInfected;
                infectedNode = inf;
            }
        }
        if (numInfected == 1) {
            int s = iso.size();
            if (s > maxInfected) {
                maxInfected = s;
                candidates.clear();
                candidates.push_back(infectedNode);
            } else if (s == maxInfected) {
                candidates.push_back(infectedNode);
            }
        }
    }

    if (candidates.size() > 0) {
        std::sort(candidates.begin(), candidates.end());
        return candidates[0];
    }

    return initial[0];
}
