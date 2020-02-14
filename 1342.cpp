int numberOfSteps (int num) {
    int steps = 0;
    for(;num > 0;++steps, num % 2 == 0 ? num /= 2 : --num);
    return steps;
}
