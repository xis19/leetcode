def maximum69Number (num: int) -> int:
    s_num = str(num)

    if '6' in s_num:
        s_num = s_num.replace('6', '9', 1)
        return int(s_num)

    return num
