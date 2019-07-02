#include <cmath>
#include <vector>

std::vector<int> distributeCandies(int candies, int num_people) {
    std::vector<int> result(num_people, 0);

    const int N = (std::sqrt(1 + 8 * (long) candies) - 1) / 2;
    const int ROUNDS = N / num_people;
    const int RESIDUE = N % num_people;
    const int REMAINING = candies - N * (N + 1) / 2;

    for (int i = 0; i < num_people; ++i) {
        if (i < RESIDUE) {
            result[i] = (i + 1) * (ROUNDS + 1) + ROUNDS * (ROUNDS + 1) / 2 * num_people;
        } else if (i == RESIDUE) {
            result[i] = (i + 1) * ROUNDS + ROUNDS * (ROUNDS - 1) / 2 * num_people + REMAINING;
        } else {
            result[i] = (i + 1) * ROUNDS + ROUNDS * (ROUNDS - 1) / 2 * num_people;
        }
    }

    return result;
}
