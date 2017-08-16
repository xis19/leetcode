int countSegments(char* s) {
    int result = 0;
    const char* i = s;
    _Bool lastNonempty = false;
    while(*i) {
        if (*i != ' ')
            lastNonempty = true;
        else
            result += lastNonempty, lastNonempty = false;
        ++i;
    }
    result += lastNonempty;
    return result;
}
