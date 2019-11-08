#include <algorithm>
#include <cctype>
#include <string>
#include <vector>

std::vector<bool> camelMatch(std::vector<std::string>& queries, std::string pattern) {
    // One way is to split the string into differnt parts, but this could be difficult.
    auto match = [](const std::string& s, const std::string& p) -> bool {
        auto sI = s.begin(), sE = s.end();
        auto pI = p.begin(), pE = p.end();

        while (sI != sE) {
            if (pI == pE) {
                if (std::isupper(*sI)) {
                    return false;
                }
            } else {
                if (*sI == *pI) {
                    ++pI;
                } else {
                    if (std::isupper(*sI)) {
                        return false;
                    }
                }
            }

            ++sI;
        }

        return pI == pE;
    };

    std::vector<bool> result;
    std::transform(queries.begin(), queries.end(), std::back_inserter(result),
            [&pattern, &match](const std::string& q) { return match(q, pattern); });

    return result;
}
