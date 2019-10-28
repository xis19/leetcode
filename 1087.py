import re

from typing import *

def expand(S: str) -> List[str]:
    def _expand(prefix: str, remaining: str) -> List[str]:
        lbracket = remaining.find('{')
        if lbracket == -1:
            return [prefix + remaining]

        prefix += remaining[:lbracket]
        choices_str, new_remaining = remaining[lbracket + 1:].split('}', 1)
        choices = choices_str.split(',')

        result = []
        for choice in choices:
            result.extend(_expand(prefix + choice, new_remaining))

        return result

    return sorted(_expand('', S))


print(expand("{a,b}c{d,e}f"))
