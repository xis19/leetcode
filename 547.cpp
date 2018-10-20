#include <stack>
#include <unordered_set>
#include <vector>

int findCircleNum(const std::vector<std::vector<int>>& M) {
    const int STUDENTS = M.size();

    std::unordered_set<int> unvisitedStudents;
    unvisitedStudents.reserve(STUDENTS);
    for(int i = 0; i < STUDENTS; ++i) unvisitedStudents.insert(i);

    int numCircles = 0;
    while(!unvisitedStudents.empty()) {
        // Randomly pick one student
        int studentID = *unvisitedStudents.begin();

        ++numCircles;

        std::stack<int> currentCircle;
        currentCircle.push(studentID);
        while(!currentCircle.empty()) {
            int currentStudentID = currentCircle.top();
            currentCircle.pop();

            unvisitedStudents.erase(currentStudentID);
            for(int possibleFriendID = 0; possibleFriendID < STUDENTS; ++possibleFriendID) {
                if (M[currentStudentID][possibleFriendID]) {
                    if (unvisitedStudents.find(possibleFriendID) != unvisitedStudents.end()) {
                        currentCircle.push(possibleFriendID);
                    }
                }
            }
        }
    }

    return numCircles;
}
