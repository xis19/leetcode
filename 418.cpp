#include <algorithm>
#include <cassert>
#include <string>
#include <vector>

int wordsTypingSlower(const std::vector<std::string>& sentence, int rows, int cols) {
    assert(sentence.size() > 0);

    std::vector<int> lens(sentence.size());
    std::transform(sentence.begin(), sentence.end(), lens.begin(), [](const std::string& s) { return s.size(); });

    int numSentences(0);
    auto iter = lens.begin();
    for (int r = 0; r < rows; ++r) {
        int col(0);
        while(col < cols) {
            if (col + *iter <= cols) {
                col += *iter++ + 1;
                if (iter == lens.end()) {
                    ++numSentences;
                    iter = lens.begin();
                }
            } else {
                break;
            }
        }
    }

    return numSentences;
}


int wordsTypingSlow(const std::vector<std::string>& sentence, int rows, int cols) {
    assert(sentence.size() > 0);

    std::vector<int> lens(sentence.size());
    std::transform(sentence.begin(), sentence.end(), lens.begin(), [](const std::string& s) { return s.size(); });

    int numSentences(0);
    auto iter = lens.begin();
    std::vector<int> rowNumSentences;
    for (int r = 0; r < rows; ++r) {
        if (iter == lens.begin() && rowNumSentences.size() > 0) {
            // We reached the initial status -- start at the beginning of a
            // sentence and the beginning of a row
            break;
        }

        int col(0);
        while(col < cols) {
            if (col + *iter <= cols) {
                col += *iter++ + 1;
                if (iter == lens.end()) {
                    ++numSentences;
                    iter = lens.begin();
                }
            } else {
                break;
            }
        }
        rowNumSentences.push_back(numSentences);
    }

    int lenRowNumSentences = rowNumSentences.size();
    int result = rowNumSentences.back() * (rows / lenRowNumSentences);
    if (rows % lenRowNumSentences != 0) {
        result += rowNumSentences[rows % lenRowNumSentences - 1];
    }
    return result;
}
