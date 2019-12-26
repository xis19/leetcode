from typing import List

def ambiguousCoordinates(S: str) -> List[str]:
    s = S[1:-1]
    result = set()

    def get_possible_decimal(t: str) -> List[str]:
        if len(t) == 1:
            return [t]
        res = []
        if not (t.startswith('0') and len(t) > 1):
            res.append(t)
        for x in range(1, len(t)):
            lhs, rhs = t[:x], t[x:]
            if lhs.startswith('0') and len(lhs) > 1:
                continue
            if rhs.endswith('0'):
                continue
            res.append(lhs + '.' + rhs)
        return res

    for x in range(1, len(s)):
        xx, yy = s[:x], s[x:]
        x_possibles = get_possible_decimal(xx)
        y_possibles = get_possible_decimal(yy)
        for x_possible in x_possibles:
            for y_possible in y_possibles:
                result.add('(' + x_possible + ', ' + y_possible + ')')

    return list(result)


print(ambiguousCoordinates("(123)"))
print(ambiguousCoordinates("(00011)"))
print(ambiguousCoordinates("(0123)"))
