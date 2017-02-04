int addDigits(int num) {
    if (num == 0) return 0;
    int mod = num % 9;
    return mod ? mod : 9;
}

int addDigitsSlow(int num) {
    int sum = 0;

    while(num >= 10) {
        while(num) sum += num % 10, num /= 10;
        num = sum;
        sum = 0;
    }

    return num;
}
