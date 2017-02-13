#include <string>
#include <vector>

std::vector<std::string> readBinaryWatch(int num) {
    auto weight = [](int v) -> int {
        // Brian Kernighans way
        int count(0);
        while(v) {
            count += (v & 1);
            v >>= 1;
        }
        return count;
    };

    std::vector<std::string> result;

    for(int i = 0; i <= num; ++i) {
        int hour_bits = i, minute_bits = num - i;

        std::vector<std::string> hours, minutes;
        for(int i = 0; i <= 11; ++i) {
            if (weight(i) == hour_bits) {
                hours.emplace_back(std::to_string(i));
            }
        }
        for(int i = 0; i <= 59; ++i) {
            if (weight(i) == minute_bits) {
                std::string s = std::to_string(i);
                if (s.size() == 1) s = '0' + s;
                minutes.emplace_back(s);
            }
        }

        for(const auto& hour: hours) {
            for(const auto& minute: minutes) {
                result.push_back(hour + ':' + minute);
            }
        }
    }

    return result;
}
