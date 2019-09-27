template <int i>
struct Tribonacci {
    enum {
        VALUE = Tribonacci<i - 3>::VALUE + Tribonacci<i - 2>::VALUE + Tribonacci<i - 1>::VALUE
    };
};

template <>
struct Tribonacci<0> {
    enum {
        VALUE = 0
    };
};

template <>
struct Tribonacci<1> {
    enum {
        VALUE = 1
    };
};

template <>
struct Tribonacci<2> {
    enum {
        VALUE = 1
    };
};

const int TRIBONACCI[] = {
    Tribonacci<0>::VALUE,
    Tribonacci<1>::VALUE,
    Tribonacci<2>::VALUE,
    Tribonacci<3>::VALUE,
    Tribonacci<4>::VALUE,
    Tribonacci<5>::VALUE,
    Tribonacci<6>::VALUE,
    Tribonacci<7>::VALUE,
    Tribonacci<8>::VALUE,
    Tribonacci<9>::VALUE,
    Tribonacci<10>::VALUE,
    Tribonacci<11>::VALUE,
    Tribonacci<12>::VALUE,
    Tribonacci<13>::VALUE,
    Tribonacci<14>::VALUE,
    Tribonacci<15>::VALUE,
    Tribonacci<16>::VALUE,
    Tribonacci<17>::VALUE,
    Tribonacci<18>::VALUE,
    Tribonacci<19>::VALUE,
    Tribonacci<20>::VALUE,
    Tribonacci<21>::VALUE,
    Tribonacci<22>::VALUE,
    Tribonacci<23>::VALUE,
    Tribonacci<24>::VALUE,
    Tribonacci<25>::VALUE,
    Tribonacci<26>::VALUE,
    Tribonacci<27>::VALUE,
    Tribonacci<28>::VALUE,
    Tribonacci<29>::VALUE,
    Tribonacci<30>::VALUE,
    Tribonacci<31>::VALUE,
    Tribonacci<32>::VALUE,
    Tribonacci<33>::VALUE,
    Tribonacci<34>::VALUE,
    Tribonacci<35>::VALUE,
    Tribonacci<36>::VALUE,
    Tribonacci<37>::VALUE
};

int tribonacci(int n) {
    return TRIBONACCI[n];
}
