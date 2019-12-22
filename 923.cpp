#include <map>
#include <vector>


int threeSumMulti(const std::vector<int>& A, int target) {
    const long MODULUS = 1e9 + 7;
    std::map<int, long> mapCount;
    for (auto v: A) {
        if (mapCount.find(v) == mapCount.end()) {
            mapCount[v] = 0;
        }
        ++mapCount[v];
    }

    long result = 0;
    for (auto iIter = mapCount.begin(); iIter != mapCount.end(); ++iIter) {
        int adjustedTarget = target - iIter->first;

        long partialResult = 0;

        // Corner case -- iIter->second > 1
        if (iIter->second > 1) {
            int adjusted2Target = adjustedTarget - iIter->first;
            auto _ = mapCount.find(adjusted2Target);
            if (_ != mapCount.end() && _->first >= iIter->first) {
                if (_ == iIter) {
                    if (iIter->second > 2) {
                        // Choose 3 from iter->second
                        partialResult += iIter->second *
                            (iIter->second - 1) * (iIter->second - 2) / 6;
                    }
                } else {
                    partialResult += iIter->second *
                        (iIter->second - 1) * _->second / 2;
                }
                partialResult %= MODULUS;
            }
        }

        for (auto jIter = std::next(iIter); jIter != mapCount.end(); ++jIter) {
            auto adjusted2Target = adjustedTarget - jIter->first;
            if (adjusted2Target < jIter->first) {
                break;
            } else if (adjusted2Target == jIter->first) {
                if (jIter->second >= 2) {
                    partialResult += iIter->second *
                        jIter->second * (jIter->second - 1) / 2;
                }
            } else {
                auto kIter = mapCount.find(adjusted2Target);
                if (kIter != mapCount.end()) {
                    partialResult += iIter ->second *
                        jIter->second * kIter->second;
                }
            }
            partialResult %= MODULUS;
        }

        result += partialResult;
        result %= MODULUS;
    }

    return result;
}

