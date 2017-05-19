#include <map>
#include <deque>
#include <vector>

std::vector<int> killProcessSlow(std::vector<int>& pid, std::vector<int>& ppid, int kill) {
    const int NPROC = pid.size();
    std::deque<int> toBeProcessed;
    toBeProcessed.push_back(kill);

    std::vector<int> kills;
    kills.push_back(kill);

    while(toBeProcessed.size()) {
        int elem = toBeProcessed.front();
        toBeProcessed.pop_front();

        for(int i = 0; i < NPROC; ++i) {
            if (ppid[i] == elem) {
                kills.push_back(pid[i]);
                toBeProcessed.push_back(pid[i]);
            }
        }
    }

    return kills;
}

std::vector<int> killProcess(const std::vector<int>& pid, const std::vector<int>& ppid, int kill) {
    const int NPROC = pid.size();
    std::map<int, std::vector<int>> mapper;
    for(int i = 0; i < NPROC; ++i) {
        mapper[ppid[i]].push_back(pid[i]);
    }

    std::vector<int> kills;
    kills.push_back(kill);

    std::deque<int> toBeProcessed;
    toBeProcessed.push_back(kill);

    while(toBeProcessed.size()) {
        int elem = toBeProcessed.front();
        toBeProcessed.pop_front();

        if (mapper.find(elem) != mapper.end()) {
            for(auto i: mapper[elem]) {
                toBeProcessed.push_back(i);
                kills.push_back(i);
            }
        }
    }

    return kills;
}
