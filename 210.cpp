#include <list>
#include <unordered_map>
#include <unordered_set>
#include <vector>

std::vector<int> findOrder(int numCourses, const std::vector<std::vector<int>>& prerequisites) {
    // Toplogical sort approach
    // See https://en.wikipedia.org/wiki/Topological_sorting
    // Use Kahn's algorithm

    // graph[i] = {j}  --> i has edge to j
    // graphRev[i] = {j}  --> j has edge to i
    // Noticing prerequesites is in j <- i format
    std::unordered_map<int, std::unordered_set<int>> graph;
    std::unordered_map<int, std::unordered_set<int>> graphRev;
    std::vector<int> toplogicalSorted;
    toplogicalSorted.reserve(numCourses);

    for (const auto& v: prerequisites) {
        graph[v[0]].insert(v[1]);
        graphRev[v[1]].insert(v[0]);
    }

    // Find all nodes that has no incoming edges -- first round
    std::list<int> queue;
    for (int i = 0; i < numCourses; ++i) {
        if (graphRev[i].size() == 0) {
            queue.push_back(i);
        }
    }

    while(!queue.empty()) {
        auto n = queue.front();
        queue.pop_front();
        toplogicalSorted.push_back(n);

        for(auto t: graph[n]) {
            graphRev[t].erase(n);
            if (graphRev[t].size() == 0) {
                graphRev.erase(t);
                queue.push_back(t);
            }
        }
        graph.erase(n);
    }

    if (static_cast<int>(toplogicalSorted.size()) != numCourses)
        return std::vector<int>();

    return toplogicalSorted;
}
