#include <array>
#include <string>
#include <unordered_map>
#include <vector>

const std::array<std::string, 26> MORSE = {{
    ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."
}};

int uniqueMorseRepresentations(std::vector<std::string>& words) {
    std::unordered_map<std::string, int> representations;

    for(const auto& word: words) {
        std::string morse;
        for(const auto& ch: word) {
            morse += MORSE[ch - 'a'];
        }

        if (representations.find(morse) != representations.end()) {
            ++representations[morse];
        } else {
            representations[morse] = 1;
        }
    }

    return representations.size();
}
