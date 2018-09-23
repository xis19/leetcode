#include <unordered_map>
#include <vector>

bool lemonadeChange(const std::vector<int>& bills) {
    std::unordered_map<int, int> billCounter;
    billCounter[5] = 0;
    billCounter[10] = 0;
    billCounter[20] = 0;

    for(auto bill: bills) {
        switch(bill) {
        case 5:
            ++billCounter[5];
            break;
        case 10:
            if (billCounter[5] <= 0) return false;
            --billCounter[5];
            ++billCounter[10];
            break;
        case 20:
            if (billCounter[10] > 0) {
                --billCounter[10];
                if (billCounter[5] <= 0) return false;
                --billCounter[5];
            } else {
                if (billCounter[5] <= 2) return false;
                billCounter[5] -= 3;
            }

            ++billCounter[20];
            break;
        default:
            return false;
        }
    }
    return true;
}
