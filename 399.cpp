#include <functional>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// Graph traverse problem!
std::vector<double> calcEquation(
        std::vector<std::pair<std::string, std::string>> equations,
        std::vector<double>& values,
        std::vector<std::pair<std::string, std::string>> queries) {
    std::unordered_map<std::string, std::unordered_map<std::string, double>> graph;

    // Prepare the graph
    {
        const int NEQNS = equations.size();
        for(int i = 0; i < NEQNS; ++i) {
            const std::string& F = equations[i].first;
            const std::string& T = equations[i].second;
            const double V = values[i];
            graph[F][T] = V;
            graph[T][F] = 1.0 / V;
        }
    }

    // Search the graph for queries
    std::vector<double> result;
    for(const auto& query: queries) {
        const std::string& F = query.first;
        const std::string& T = query.second;

        // If the node is not included in start/end, fail
        if (graph.find(F) == graph.end() || graph.find(T) == graph.end()) {
            result.push_back(-1);
            continue;
        }

        // A self-reference, skip
        if (F == T) {
            result.push_back(1);
            continue;
        }


        std::unordered_set<std::string> visited;
        std::function<std::pair<bool, double>(const std::string&, double)> visit = [&](const std::string& vertex, double val) {
            visited.insert(vertex);
            if (vertex == T) {
                return std::make_pair(true, val);
            }

            for(const auto& n: graph[vertex]) {
                if (visited.find(n.first) != visited.end()) {
                    continue;
                }
                auto r = visit(n.first, val * n.second);
                if (r.first) {
                    return r;
                }
            }

            return std::make_pair(false, -1.0);
        };

        result.push_back(visit(F, 1.0).second);
    }

    return result;
}
