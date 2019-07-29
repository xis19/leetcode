#include <list>
#include <string>

std::string predictPartyVictory(std::string& senate) {
    std::list<char> senateList;
    std::copy(senate.begin(), senate.end(), std::back_inserter(senateList));

    typedef decltype(senateList.begin()) iter_t;
    auto find = [&senateList](iter_t i) -> iter_t {
        char lookFor = *i == 'R' ? 'D' : 'R';
        iter_t j = std::next(i);
        while (j != senateList.end()) {
            if (*j != lookFor) ++j; else return j;
        }
        j= senateList.begin();
        while (j != i) {
            if (*j != lookFor) ++j; else return j;
        }
        return senateList.end();
    };

    iter_t i = senateList.begin();
    for(;;) {
        auto j = find(i);
        if (j == senateList.end()) break;
        senateList.erase(j);
        i = std::next(i);
        if (i == senateList.end()) i = senateList.begin();
    }

    return *i == 'R' ? "Radiant" : "Dire";
}
