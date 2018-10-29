#include <algorithm>
#include <list>
#include <string>
#include <unordered_set>
#include <vector>
#include <utility>

std::vector<std::vector<std::string>> accountsMerge(const std::vector<std::vector<std::string>>& accounts) {
    typedef std::list<std::pair<std::string, std::unordered_set<std::string>>> merge_t;
    merge_t merged;
    for(const auto& account: accounts) {
        const std::string& name = account[0];

        std::vector<merge_t::iterator> merging;
        for(size_t i = 1; i < account.size(); ++i) {
            const std::string& email = account[i];
            for(auto iter = merged.begin(); iter != merged.end(); ++iter) {
                if (iter->first != name) {
                    continue;
                }
                if (iter->second.find(email) == iter->second.end()) {
                    continue;
                }
                if (std::find(merging.begin(), merging.end(), iter) == merging.end())
                    merging.push_back(iter);
            }
        }

        if (merging.size() == 0) {
            merged.push_back(
                std::make_pair(
                    name,
                    std::unordered_set<std::string>(std::next(account.begin()), account.end())
                )
            );
            continue;
        }

        for(size_t i = 1; i < merging.size(); ++i) {
            for(auto item: merging[i]->second) {
                merging[0]->second.insert(item);
            }
        }
        for(size_t i = 1; i < account.size(); ++i) {
            merging[0]->second.insert(account[i]);
        }

        while(merging.size() > 1) {
            merged.erase(merging.back());
            merging.pop_back();
        }
    }

    std::vector<std::vector<std::string>> result;
    for(const auto& item: merged) {
        std::vector<std::string> record;
        record.reserve(item.second.size() + 1);
        std::copy(item.second.begin(), item.second.end(), std::back_inserter(record));
        std::sort(std::next(record.begin()), record.end());

        result.emplace_back(record);
    }

    return result;
}
