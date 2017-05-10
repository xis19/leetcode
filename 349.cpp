#include <algorithm>
#include <set>
#include <vector>

std::vector<int> intersection(const std::vector<int>& n1, const std::vector<int>& n2) {
    std::set<int> s1(std::begin(n1), std::end(n1));
    std::set<int> s2(std::begin(n2), std::end(n2));
    std::vector<int> v;
    std::copy_if(std::begin(s1), std::end(s1), std::back_inserter(v),
                 [&s2](int v) { return s2.find(v) != std::end(s2); });
    return v;
}
