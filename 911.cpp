#include <algorithm>
#include <unordered_map>
#include <vector>

class TopVotedCandidate {
    const std::vector<int>& persons;
    const std::vector<int>& times;
    const int LEN;
    std::vector<int> leadingAtTime;
public:
    TopVotedCandidate(const std::vector<int>& _persons, const std::vector<int>& _times) :
            persons(_persons), times(_times), LEN(times.size()){
        // We calculate the leading person at given time
        int maxPerson = -1;
        int maxCount = -1;
        std::unordered_map<int, int> personCount;
        for(auto person: persons) {
            if (personCount.find(person) == personCount.end()) {
                personCount[person] = 0;
            }
            ++personCount[person];
            if (personCount[person] >= maxCount) {
                maxPerson = person;
                maxCount = personCount[person];
            }
            leadingAtTime.push_back(maxPerson);
        }
    }

    int q(int t) {
        // Bisect search
        // Note: In C++, lower_bound is the element equal or larger than the
        // given value, upper_bound is the element larger than the given value.
        int lo = 0, hi = LEN - 1;
        int mid = (hi - lo) / 2 + lo;
        while (lo <= hi) {
            if (times[mid] == t) {
                break;
            }

            if (times[mid] < t) {
                if (mid + 1 <= hi && times[mid + 1] <= t) {
                    lo = mid + 1;
                    mid = (hi - lo) / 2 + lo;
                } else {
                    break;
                }
            }

            if (times[mid] > t) {
                hi = mid - 1;
                mid = (hi - lo) / 2 + lo;
            }
        }

        return leadingAtTime[mid];
    }
};

