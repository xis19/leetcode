#include <algorithm>
#include <deque>
#include <unordered_map>
#include <vector>

std::vector<int> deckRevealedIncreasing(std::vector<int>& deck) {
    // For the example, [17, 13, 11, 2, 3, 5, 7], because every even indexed
    // number will be taken out in order, we could use the sort order:
    //      2 x 3 y 5 z 7
    // while x, y, z are undetermined, we then simulate a pop
    //      2 x 3 y 5 z 7
    //        3 y 5 z 7 x
    //          5 z 7 x y
    //            7 x y z
    //              y z x
    //                x z
    //                  z
    // so x = 13, y = 11, z = 17
    //
    // If the list is [2, 3, 5, 11, 13, 17],
    //      2 x 3 y 5 z
    //        3 y 5 z x
    //          5 y z x
    //            z x y
    //              y x
    //                x
    // We could use negative number for placeholder
    const int LEN = deck.size();
    std::sort(deck.begin(), deck.end());

    std::deque<int> testDeck(LEN, 0);
    std::vector<int> result(LEN, 0);
    // Fill the even indiced number
    int index = 0;
    for (int i = 0; i < LEN; ++i) {
        if (index % 2 == 0) {
            testDeck[i] = deck[index++];
            result[i] = testDeck[i];
        } else {
            testDeck[i] = -i;
        }
    }

    // Now simulate a popup to determine the order of x, y, z, etc.
    std::vector<int> undeterminedOrderIndex;
    while (!testDeck.empty()) {
        int value = testDeck.front();
        testDeck.pop_front();
        if (value < 0) undeterminedOrderIndex.push_back(-value);

        if (!testDeck.empty()) {
            testDeck.push_back(testDeck.front());
            testDeck.pop_front();
        }
    }

    // Now fill up the result base on undeterminedOrderIndex
    for (auto undetermindIndex: undeterminedOrderIndex) {
        result[undetermindIndex] = deck[index++];
    }

    return result;
}

