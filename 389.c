char findDifference(char* s, char* t) {
    char count[26] = {0};
    for(; *s != 0; ++s) ++count[*s - 'a'];
    for(; *t != 0; ++t) --count[*t - 'a'];
    for(int i = 0; i < 26; ++i) if (count[i]) return i + 'a';

    /* Additional return to avoid conmpiler warning */
    return 'a';
}
