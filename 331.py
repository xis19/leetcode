def isValidSerialization(preorder: str) -> bool:
    preordered = preorder.split(',')
    expect_elements = 1

    while len(preordered) > 0:
        next_row_elements = 0
        for i in range(expect_elements):
            # Incomplete...
            if len(preordered) == 0:
                return False

            elem = preordered.pop(0)
            if elem == '#':
                continue
            else:
                next_row_elements += 2
        expect_elements = next_row_elements
        if len(preordered) < expect_elements:
            return False
        if expect_elements == 0 and len(preordered) > 0:
            return False

    return True
