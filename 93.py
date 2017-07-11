def restoreIpAddressesEnum(s):
    def is_valid(part):
        int_part = int(part)
        if int_part > 255 or int_part < 0:
            return False
        if len(part) > 1 and part[0] == '0':
            return False
        return True

    LEN = len(s)
    result = []
    for a in range(0, LEN - 3):
        part_1 = s[:a + 1]
        if not is_valid(part_1):
            continue

        for b in range(a + 1, LEN - 2):
            part_2 = s[a + 1:b + 1]
            if not is_valid(part_2):
                continue

            for c in range(b + 1, LEN - 1):
                part_3 = s[b + 1: c + 1]
                part_4 = s[c + 1:]
                if not (is_valid(part_3) and is_valid(part_4)):
                    continue

                result.append('.'.join([part_1, part_2, part_3, part_4]))

    return result

import ipdb
ipdb.set_trace()
print(restoreIpAddressesEnum('010010'))
