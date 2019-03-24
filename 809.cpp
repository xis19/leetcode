#include <string>
#include <vector>

int expressiveWords(const std::string& S, const std::vector<std::string>& words) {
    typedef std::vector<std::pair<char, int>> CompressedWord;

    auto compress = [&](const std::string& s, CompressedWord& res) {
        for(auto ch: s) {
            if (res.empty() || res.back().first != ch) {
                res.push_back(std::make_pair(ch, 1));
            } else {
                ++res.back().second;
            }
        }
    };
    CompressedWord incoming;
    compress(S, incoming);

    int result(0);
    for(const auto& word: words) {
        CompressedWord w;
        compress(word, w);

        if (w.size() != incoming.size()) {
            continue;
        }

        const int SIZE = w.size();
        bool match = true;
        for(int i = 0; i < SIZE; ++i) {
            if (incoming[i].first != w[i].first ||
                (incoming[i].second < 3 && w[i].second < incoming[i].second) ||
                incoming[i].second < w[i].second) {
                match = false;
                break;
            }
        }
        result += match;
    }

    return result;
}
