/* The Ruby implementation is too slow.
def three_sum(nums)
  nums.sort!

  result = []

  used_pair = Set.new
  nums.each.with_index do |v1, i1|
    lo = i1 + 1
    hi = nums.length - 1
    while lo < hi
      lo += 1 while used_pair.include?([v1, nums[lo]]) && lo < hi
      break if lo == hi
      v2 = nums[lo]
      used_pair << [v1, v2]

      target = - v1 - v2
      hi -= 1 while nums[hi] > target && hi > lo + 1
      if nums[hi] == target
        result << [v1, v2, nums[hi]]
      end
    end
  end

  result
end
 */

#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    const int LEN = nums.size();

    sort(nums.begin(), nums.end());

    vector<vector<int>> result;
    unordered_map<int, unordered_set<int>> v12;

    for(int i = 0; i < LEN; ++i) {
        int v1 = nums[i];
        int lo = i + 1;
        int hi = LEN - 1;
        auto& s = v12[v1];
        while(lo < hi) {
            while(s.find(nums[lo]) != s.end() && lo < hi) ++lo;
            if (lo == hi) break;

            s.insert(nums[lo]);
            int target = - v1 - nums[lo];
            while(nums[hi] > target && hi > lo + 1) --hi;
            if (nums[hi] == target) {
                result.push_back(vector<int>{v1, nums[lo], nums[hi]});
            }
        }
    }

    return result;
}
