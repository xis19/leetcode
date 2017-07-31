import re

def isNumber(s: str) -> bool:
    return re.match(r'^\s*[+-]?((\d+(\.\d*)?)|(\.\d+))([Ee][+-]?\d+)?\s*$', s) is not None
