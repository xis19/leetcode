def decodeString(s):
    num_stack = []
    str_stack = ['']

    LEN = len(s)
    i = 0
    while i < LEN:
        if s[i].isdigit():
            r = ''
            while s[i] != '[':
                r += s[i]
                i += 1
            num_stack.append(int(r))
            str_stack.append('')
        elif s[i].isalpha():
            str_stack[-1] += s[i]
        elif s[i] == ']':
            r = str_stack[-1] * num_stack[-1]
            str_stack.pop()
            num_stack.pop()
            str_stack[-1] += r

        i += 1

    return str_stack[-1]
