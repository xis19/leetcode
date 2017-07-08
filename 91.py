import json

def numDecodings(s):
    def isValid(chs):
        if chs[0] != '0' and 1 <= int(chs) <= 26:
            return 1
        return 0

    if len(s) == 0:
        return 0

    LEN = len(s)
    DP = []

    DP.append(isValid(s[0]))
    if LEN == 1:
        return DP[-1]

    DP.append(isValid(s[0:2]) + (DP[0] if isValid(s[1]) else 0))
    if LEN == 2:
        return DP[-1]

    for i in range(2, LEN):
        DP.append((DP[i - 2] if isValid(s[i - 1:i + 1]) else 0) +
                  (DP[i - 1] if isValid(s[i]) else 0))

    return DP[-1]

print(numDecodings("01"))
print(numDecodings("1201315274"))
