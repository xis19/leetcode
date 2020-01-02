def read4(buf):
    pass


class Solution:
    def __init__(self):
        self._buffer = []

    def read(self, buf, n):
        while len(self._buffer) < n:
            content = [None] * 4
            read4(content)
            while content and not content[-1]:
                content.pop()
            if not content:
                break
            self._buffer += content

        max_extractable = min(n, len(self._buffer))
        for x in range(max_extractable):
            buf[x] = self._buffer[x]
        self._buffer = self._buffer[n:]
        return max_extractable
