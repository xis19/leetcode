int guess(int num);

int guessNumber(int n) {
    int lo = 1, hi = n;
    int g = lo + (hi - lo) / 2;
    int state = guess(g);
    while(state) {
        switch(state) {
            case 1:
                lo = g + 1;
                break;
            case -1:
                hi = g;
                break;
        }
        g = lo + (hi - lo) / 2;
        state = guess(g);
    }

    return g;
}
