#include <string>

bool checkRecord(std::string s) {
    return (s.find_first_of('A') == s.find_last_of('A') && s.find("LLL") == std::string::npos);
}
