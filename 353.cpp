#include <deque>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

class SnakeGame {
    std::deque<std::pair<int, int>> snake{{0, 0}};
    int snakeLength = 1;

    std::unordered_map<char, std::pair<int, int>> DIRS = {
        {'U', {0, -1}},
        {'D', {0, 1}},
        {'L', {-1, 0}},
        {'R', {1, 0}}
    };

    const int WIDTH;
    const int HEIGHT;
    std::deque<std::pair<int, int>> fruit;
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, const std::vector<std::vector<int>>& food) :
            WIDTH(width), HEIGHT(height) {
        for (auto f: food) {
            fruit.push_back({f[1], f[0]});
        }
    }

    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down
        @return The game's score after the move. Return -1 if game over.
        Game over when snake crosses the screen boundary or bites its body. */
    int move(const std::string& direction) {
        auto dir = DIRS[direction[0]];
        auto head = snake.back();
        std::pair<int, int> next{head.first + dir.first, head.second + dir.second};

        auto back = snake.front();
        snake.pop_front();

        if (next.first < 0 || next.first >= WIDTH || next.second < 0 ||
                next.second >= HEIGHT) {
            return -1;
        }
        for (const auto& body: snake) {
            if (body.first == next.first && body.second == next.second) {
                return -1;
            }
        }
        if (fruit.front().first == next.first && fruit.front().second == next.second) {
            // Is food
            fruit.pop_front();
            ++snakeLength;
            snake.push_front(back);
        }
        snake.push_back(next);
        return snakeLength - 1;
    }
};

