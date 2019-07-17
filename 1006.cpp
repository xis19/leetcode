int clumsy(int N) {
    auto evalHead = [](int x) {
        return x * (x - 1) / (x - 2) + x - 3;
    };

    auto evalBody = [](int x) {
        return x * (x - 1) / (x - 2) - x + 3;
    };

    auto evalSmaller = [](int x) {
        if (x == 3) return 3 * 2 / 1;
        if (x == 2) return 2 / 1;
        if (x == 1) return 1;
        return 0;
    };

    if (N < 4) {
        return evalSmaller(N);
    }

    int s = evalHead(N);
    int n = N - 4;
    while(n >= 4) {
        s -= evalBody(n);
        n -= 4;
    }
    s -= evalSmaller(n);

    return s;
}
