def solveEquation(equation: str) -> str:

    def reduce_expression(expr: str) -> tuple:
        x_coeff = 0
        val = 0

        def parse_x(expr: str) -> int:
            expr = expr.rstrip('x')
            try:
                coefficient = int(expr)
            except ValueError:
                coefficient = -1 if expr == '-' else 1
            return coefficient

        def parse_val(expr: str) -> int:
            return int(expr)

        residue = ''
        for ch in expr:
            if ch in '+-':
                if residue.endswith('x'):
                    x_coeff += parse_x(residue)
                elif len(residue) != 0:
                    val += parse_val(residue)
                residue = ch
            else:
                residue += ch

        if residue.endswith('x'):
            x_coeff += parse_x(residue)
        elif len(residue) != 0:
            val += parse_val(residue)

        return (x_coeff, val)

    lhs, rhs = equation.split('=')
    lcoeff, lval = reduce_expression(lhs)
    rcoeff, rval = reduce_expression(rhs)

    l = lcoeff - rcoeff
    r = rval - lval
    if l == 0 and r == 0:
        return 'Infinite solutions'
    elif l == 0 and r != 0:
        return 'No solution'
    else:
        return 'x={}'.format(int(r / l))


print(solveEquation('x+5-3+x=6+x-2'))
print(solveEquation('x=x'))
print(solveEquation('2x=x'))
print(solveEquation('2x+3x-6x=x+2'))
print(solveEquation('x=x+2'))
print(solveEquation('-x=-1'))
