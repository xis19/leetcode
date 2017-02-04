#include <string>
#include <vector>

std::vector<std::string> fizzBuzz(int n) {
    std::vector<std::string> result(n);

    for(int i = 1; i <= n; ++i) {
        if (i % 3 && i % 5)
            result[i - 1] = std::to_string(i);
        else if (i % 3)
            result[i - 1] = "Buzz";
        else if (i % 5)
            result[i - 1] = "Fizz";
        else
            result[i - 1] = "FizzBuzz";
    }

    return result;
}
