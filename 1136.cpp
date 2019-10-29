#include <unordered_map>
#include <unordered_set>
#include <vector>

int minimumSemesters(int N, const std::vector<std::vector<int>>& relations) {
    // Corner case -- N = 0
    if (N == 0) return 0;

    // Toplogical sort with layers
    std::unordered_map<int, std::unordered_set<int>> relationMap;
    for (auto& relation: relations) {
        relationMap[relation[1]].insert(relation[0]);
    }

    // We repeatly find those nodes that has no prerequesites.
    int semesters = 0;
    std::unordered_set<int> takenCourses;   // this could be a flag array
    while (takenCourses.size() != static_cast<size_t>(N)) {
        // Find all courses that prerequesites fulfilled / no prereqs
        std::vector<int> noPrereqs;
        for (int i = 1; i <= N; ++i) {
            // Has taken it?
            if (takenCourses.find(i) != takenCourses.end()) {
                continue;
            }
            // Has unfulfilled prereqs?
            if (!relationMap[i].empty()) {
                continue;
            }
            noPrereqs.push_back(i);
            takenCourses.insert(i);
        }

        if (noPrereqs.size() == 0) {
            // We could not find any courses that does not require prerequesites
            // Circular dependency?
            return -1;
        }

        // Take those courses
        ++semesters;

        // Remove the prereqs -- we have taken the courses already
        for (auto takenThisSemester: noPrereqs) {
            for (auto& relation: relationMap) {
                if (relation.second.find(takenThisSemester) != relation.second.end()) {
                    relation.second.erase(takenThisSemester);
                }
            }
        }
    }

    return semesters;
}
