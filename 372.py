from typing import List

def superPow(a: int, b: List[int]) -> int:
    p = int(''.join(str(x) for x in b))
    def pow2(v, exp):
        if exp == 1:
            return v % 1337
        elif exp == 2:
            return (v * v) % 1337
        else:
            v2 = (v * v) % 1337
            x = pow2(v2, exp // 2)
            if exp % 2 == 1:
                x = x * v
            return x % 1337
    return pow2(a, p)
