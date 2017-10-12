class TwoSumSlow(object):

    def __init__(self):
        self.value_set = set()
        self.sum_set = set()

    def add(self, number):
        if (number, 1) in self.value_set:
            self.value_set.remove((number, 1))
            self.value_set.add((number, 2))
            self.sum_set.add(number + number)
        elif (number, 2) in self.value_set:
            pass
        else:
            # Note the order!
            for n, _ in self.value_set:
                self.sum_set.add(n + number)
            self.value_set.add((number, 1))

    def find(self, value):
        return value in self.sum_set


class TwoSum(object):

    def __init__(self):
        self.value_set = collections.defaultdict(int)

    def add(self, number):
        self.value_set[number] += 1

    def find(self, value):
        for n1 in self.value_set:
            n2 = value - n1
            if n2 in self.value_set:
                if n2 == n1 and self.value_set[n1] != 2:
                    continue
                return True
        return False
