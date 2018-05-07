#include <functional>
#include <vector>

std::vector<std::vector<int>> allPathsSourceTarget(const std::vector<std::vector<int>>& graph) {
    const int N = graph.size();

    std::vector<std::vector<int>> result;

    std::function<void(int, std::vector<int>)> traverse = [&graph, N, &result, &traverse](int index, std::vector<int> path) -> void {
        path.push_back(index);

        if (index ==  N - 1) {
            result.emplace_back(path);
            return;
        }

        for(auto connectedIndex: graph[index]) {
            traverse(connectedIndex, path);
        }
    };

    traverse(0, std::vector<int>{});

    return result;
}
