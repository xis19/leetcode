#include <cmath>
#include <vector>

double largestTriangleArea(const std::vector<std::vector<int>>& points) {
    // Use cross product: the area of ABC is |AB x AC| / 2
    static auto triangleArea = [](const std::vector<int>& p1, const std::vector<int>& p2, const std::vector<int>& p3) -> double {
        double p12x = p2[0] - p1[0];
        double p12y = p2[1] - p1[1];
        double p13x = p3[0] - p1[0];
        double p13y = p3[1] - p1[1];

        return std::abs((p12x * p13y  - p12y * p13x) / 2);
    };


    const int NPOINTS = points.size();
    double maxArea(0);
    for(int i = 0; i < NPOINTS; ++i) {
        for(int j = i + 1; j < NPOINTS; ++j) {
            for(int k = j + 1; k < NPOINTS; ++k) {
                maxArea = std::max(maxArea, triangleArea(points[i], points[j], points[k]));
            }
        }
    }

    return maxArea;
}
