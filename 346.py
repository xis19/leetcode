class MovingAverage(object):

    def __init__(self, size):
        """
        Initialize your data structure here.
        :type size: int
        """
        self._window = collections.deque(maxlen=size)

    def next(self, val):
        """
        :type val: int
        :rtype: float
        """
        self._window.append(val)
        return float(sum(self._window)) / len(self._window)
