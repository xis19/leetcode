#include <list>
#include <unordered_set>
#include <unordered_map>
#include <vector>

bool possibleBipartition(int N, const std::vector<std::vector<int>>& dislikes) {
    std::unordered_map<int, std::unordered_set<int>> graph;
    for(const auto& dislike: dislikes) {
        graph[dislike[0]].insert(dislike[1]);
        graph[dislike[1]].insert(dislike[0]);
    }

    std::unordered_set<int> unvisitedVertices;
    unvisitedVertices.reserve(N);
    for (int i = 1; i <= N; ++i) unvisitedVertices.insert(i);

    std::unordered_map<int, std::unordered_set<int>> vertexTeam;
    while(!unvisitedVertices.empty()) {
        auto vertex = *unvisitedVertices.begin();

        std::list<std::pair<int, int>> queue{std::make_pair(vertex, 0)};
        while(!queue.empty()) {
            auto v = queue.front();
            queue.pop_front();

            unvisitedVertices.erase(v.first);
            vertexTeam[v.second].insert(v.first);

            int dislikeTeamId = !v.second;
            for (auto dislike: graph[v.first]) {
                // The order is important, as we need to capture conflict first
                if (vertexTeam[v.second].find(dislike) != unvisitedVertices.end()) {
                    return false;
                }
                if (unvisitedVertices.find(dislike) == unvisitedVertices.end()) {
                    continue;
                }
                queue.push_back(std::make_pair(dislike, dislikeTeamId));
            }
        }
    }

    return true;
}
