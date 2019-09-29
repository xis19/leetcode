#include <vector>
#include <utility>

class RLEIterator {
private:
    std::vector<int> storage;
    std::vector<int>::iterator iterator;
public:
    RLEIterator(const std::vector<int>& A) :
        storage(A), iterator(storage.begin()) {}

    int next(int n) {
        if (iterator == storage.end()) return -1;
        if (n <= *iterator) {
            *iterator -= n;
            return *std::next(iterator);
        } else {
            int res = *iterator;
            iterator += 2;
            return next(n - res);
        }
    }
};
