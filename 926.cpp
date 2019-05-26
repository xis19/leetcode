#include <string>
#include <vector>

int minFlipsMonoIncr(const std::string& S) {
    // Consider i-th character cI
    // S[0:i - 1] could be flipped to all 0, taking e0[i - 1] steps; or seqs
    // start with 0 and ends with 1, taking e1[i - 1] steps.
    // e0[i] = (cI != '0') + e0[i - 1];   -- if current cI is '0', no flip;
    //                                       otherwise add a flip step;
    // e1[i] =
    //      if (cI == '1') min(e0[i - 1], e1[i - 1])
    //      else min(e0[i - 1] + 1, e1[i - 1] + 1)
    //                                    -- if cI is 1, then it can be attached
    //                                       to previous e0 or e1 making a new
    //                                       e1; othherwise, we have to flip it
    //                                       to make it a new e1
    int e0(0), e1(0);
    for(auto cI: S) {
        auto e0old(e0), e1old(e1);
        e0 += (cI != '0');
        e1 = std::min(e0old, e1old) + (cI != '1');
    }
    return std::min(e0, e1);
}
