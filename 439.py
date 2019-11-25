def parseTernary(expression: str) -> str:
    LEN = len(expression)
    i = 0

    def parse_ternary():
        nonlocal i
        token = expression[i]
        i += 2  # skip ?
        left, right = parse_branches()
        if token == 'T':
            return left
        else:
            return right

    def parse_branches():
        nonlocal i
        token = expression[i]
        # In case of T?F:3
        if (token == 'T' or token == 'F') and expression[i + 1] == '?':
            left = parse_ternary()
        else:
            left = token
            i += 1

        i += 1  # skip :

        token = expression[i]
        # Corner case:
        # In case of F?8:T <EOL>
        if (token == 'T' or token == 'F') and (i + 1 < LEN and expression[i + 1] == '?'):
            right = parse_ternary()
        else:
            right = token
            i += 1

        return (left, right)

    import ipdb; ipdb.set_trace()
    return parse_ternary()


# print(parseTernary("T?T?F:5:3"))
# print(parseTernary("F?T:F?T?1:2:F?3:4"))
# print(parseTernary("F?F?3:8:T?F:T?0:F?8:T"))
