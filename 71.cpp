#include <vector>
#include <string>

std::string simplfiyPath(std::string input) {
    // To handle /. or /.. situation, we append a '/' to input, otherwise for
    // tailing item we need to duplicate the logic inside the loop, and this
    // is not good.
    input.push_back('/');

    std::vector<std::string> path;

    std::string currentItem;
    for(auto ch: input) {
        if (ch == '/') {
            if (currentItem == "." || currentItem.empty()) {
                currentItem.clear();
            } else if (currentItem == "..") {
                if (!path.empty()) path.pop_back();
                currentItem.clear();
            } else {
                path.emplace_back(std::string());
                std::swap(currentItem, path.back());
            }
        } else {
            currentItem += ch;
        }
    }

    if (path.empty()) {
        return "/";
    }

    std::string result;
    for(auto item: path) {
        result += '/' + item;
    }

    return result;
}
