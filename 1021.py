def removeOuterParentheses(S: str) -> str:
    merged = []
    current = []
    lp = 0
    for ch in S:
        if ch == '(':
            lp += 1
        else:
            lp -= 1
        current.append(ch)
        if lp == 0:
            merged.append(''.join(current[1:-1]))
            current.clear()

    return ''.join(merged)
