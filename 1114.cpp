#include <chrono>
#include <functional>
#include <thread>

using namespace std::chrono_literals;

class Foo {
    int printIndex;
public:
    Foo(): printIndex(1) {}

    void first(std::function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();

        printIndex = 2;
    }

    void second(std::function<void()> printSecond) {
        while(printIndex != 2) std::this_thread::sleep_for(2ms);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        printIndex = 3;
    }

    void third(std::function<void()> printThird) {
        while(printIndex != 3) std::this_thread::sleep_for(2ms);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        printIndex = 1;
    }
};
