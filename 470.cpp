extern int rand7();


int rand10() {
    int s = 0;

    // We first decide if we want the number > 5 or < 5
    {
        int k;
        while((k = rand7()) == 4);
        if (k < 4) s = 5;
    }

    // Then pick up a number in [1, 5]
    int k;
    while((k = rand7()) > 5);
    return k + s;
}


