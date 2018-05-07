import re

def maskPII(S: str) -> str:
    m = re.match('([A-Za-z]+)@([A-Za-z]+\.[A-Za-z]+)', S)
    if m:
        name = m.group(1).lower()
        domain = m.group(2).lower()

        name = name[0] + '*****' + name[-1]
        return name + '@' + domain

    # it is a phone number
    num_digits = 0
    digits = []
    for ch in S:
        if re.match('[0-9]', ch):
            num_digits += 1
            digits.append(ch)

    if num_digits == 10:
        return '***-***-{}'.format(''.join(digits[-4:]))
    else:
        return '+{}-***-***-{}'.format(
            '*' * (num_digits - 10),
            ''.join(digits[-4:])
        )

