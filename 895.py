class FreqStack:

    def __init__(self):
        # Maps number to its count
        self._number_count_hash = {}
        # Maps the number of frequency
        self._freq_map = [set()]
        # Use an array to decide the sequence of push
        self._stack = []


    def push(self, x: int) -> None:
        if x not in self._number_count_hash:
            self._number_count_hash[x] = 0
            self._freq_map[0].add(x)

        num_count = self._number_count_hash[x]
        self._freq_map[num_count].remove(x)

        num_count += 1
        self._number_count_hash[x] = num_count
        while len(self._freq_map) <= num_count:
            self._freq_map.append(set())

        self._freq_map[num_count].add(x)
        self._stack.append(x)

    def pop(self) -> int:
        most_recent_set = self._freq_map[-1]
        # We need to go through _stack to see which is most recently pushed
        for i in range(len(self._stack) - 1, -1, -1):
            if self._stack[i] not in most_recent_set:
                continue

            value = self._stack[i]

            self._freq_map[-1].remove(value)
            self._freq_map[-2].add(value)
            self._number_count_hash[value] -= 1

            del self._stack[i]
            if not self._freq_map[-1]:
                del self._freq_map[-1]

            return value

        return None
