class Logger(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self._last_print = {}


    def shouldPrintMessage(self, timestamp, message):
        """
        Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity.
        :type timestamp: int
        :type message: str
        :rtype: bool
        """
        last_print = self._last_print.get(message)

        if last_print is None or timestamp - last_print >= 10:
            self._last_print[message] = timestamp
            return True
        return False
