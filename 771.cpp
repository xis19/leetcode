#include <set>
#include <string>

int numJewelsInStones(const std::string& J, const std::string& S) {
    std::set<char> j;
    for(auto ch: J) j.insert(ch);
    int result(0);
    for(auto ch: S) {
        if (j.find(ch) != j.end()) ++result;
    }
    return result;
}
