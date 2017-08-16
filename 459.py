def repeatedSubstringPattern(s: str) -> bool:
    LEN = len(s)
    for i in range(1, int(LEN / 2) + 1):
        if LEN % i != 0:
            continue

        # If [0:i] is one possible periodic cell, then do a rotate
        # will not change the string
        if s == s[i:] + s[:i]:
            return True

    return False
