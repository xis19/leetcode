class NestedInteger:
    def __init__(self, value=None):
        """
        If value is not specified, initializes an empty list.
        Otherwise initializes a single integer equal to value.
        """

    def isInteger(self):
        """
        @return True if this NestedInteger holds a single integer, rather than a nested list.
        :rtype bool
        """

    def add(self, elem):
        """
        Set this NestedInteger to hold a nested list and adds a nested integer elem to it.
        :rtype void
        """

    def setInteger(self, value):
        """
        Set this NestedInteger to hold a single integer equal to value.
        :rtype void
        """

    def getInteger(self):
        """
        @return the single integer that this NestedInteger holds, if it holds a single integer
        Return None if this NestedInteger holds a nested list
        :rtype int
        """

    def getList(self):
        """
        @return the nested list that this NestedInteger holds, if it holds a nested list
        Return None if this NestedInteger holds a single integer
        :rtype List[NestedInteger]
        """


def deserialize(s: str) -> NestedInteger:
    LEN = len(s)
    index = 0

    def fetch():
        nonlocal index

        while index < LEN and s[index] == ',':
            index += 1

        if index >= LEN:
            return None
        elif s[index] == '[':
            index += 1
            return '['
        elif s[index] == ']':
            index += 1
            return ']'

        i = 0
        flag = 1
        if s[index] == '-':
            flag = -1
            index += 1

        while index < LEN and s[index].isdigit():
            i *= 10
            i += int(s[index])
            index += 1

        return i * flag

    stack = [NestedInteger()]

    token = fetch()
    while token is not None:
        if isinstance(token, int):
            stack[-1].add(NestedInteger(token))
        elif token == '[':
            stack[-1].add(NestedInteger())
            stack.append(stack[-1].getList()[-1])
        elif token == ']':
            stack.pop()

        token = fetch()

    return stack[0].getList()[0]
