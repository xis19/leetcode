def toHexspeak(num: str) -> str:
    result = hex(int(num))[2:].upper().replace('0', 'O').replace('1', 'I')
    if re.search('[0-9]', result):
        return 'ERROR'
    return result

