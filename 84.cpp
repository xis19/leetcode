#include <stack>
#include <vector>
#include <utility>

int largestRectangleArea(std::vector<int>& heights) {
    //
    //        ##
    //      ####
    //      ####  ##
    //  ##  ########
    //  ############
    //  ^^
    //
    // we consider each column, the maximum rectangle starting with
    // the column ends with the column that are lower than itself.
    //
    // Consider the column A in stack with height a, if the next column
    // B with height b >= a is taller than the current one, then B can
    // "contribute" to rectangle starting with A, while A cannot contribute
    //  to rectangle starting with B.
    //
    // On the other hand, if b < a, then B will not contribute while A
    // will contribute to B.
    //
    // We use a stack to store the index and height of the columns.
    // Every time a new colume come, we check its height. If it is taller
    // than the current one, then we store it. Else, we pop the column
    // from the top of stack, and calculate the area.
    //
    //       ##
    //    ##-##
    // ##-##-##
    // ## ## ##    <---    ##
    //  1  2  3             4
    //  ^-----^
    //     ^--^
    //
    // After the pop
    //
    // ##
    //  1   <--- because column 1, 2, 3 could still contribute to 4, we
    // simply change the index of the column to 1.

    // We use two 0s for boundary. The first 0 ensures all columns will
    // be pushed at least once. The second 0 ensures all columns will be
    // popped out from the stack.
    heights.insert(heights.begin(), 0);
    heights.push_back(0);

    const int LEN = heights.size();
    std::stack<std::pair<int, int>> s;

    int maxArea = 0;
    for(int i = 0; i < LEN; ++i) {
        int firstContributableIndex = i;
        while(s.top().second > heights[i]) {
            auto column = s.top();
            s.pop();
            // This column is taller than the incoming one, it could
            // contribute to the incoming column.
            firstContributableIndex = column.first;
            maxArea = std::max(maxArea, column.second * (i - column.first));
        }
        s.push(std::make_pair(firstContributableIndex ,heights[i]));
    }

    return maxArea;
}
