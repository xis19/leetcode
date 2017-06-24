#include <set>
#include <vector>

std::vector<int> intersect(const std::vector<int>& nums1, std::vector<int>& nums2) {
    std::multiset<int> m1(nums1.begin(), nums1.end());
    std::multiset<int> m2(nums2.begin(), nums2.end());
    std::vector<int> result;
    const auto M2END = m2.end();
    for(auto s: m1) {
        auto find = m2.find(s);
        if (find != M2END) {
            m2.erase(find);
            result.push_back(s);
        }
    }
    return result;
}
