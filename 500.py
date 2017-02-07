ROWS = [
    'qwertyuiop',
    'asdfghjkl',
    'zxcvbnm'
]

class Solution(object):
    def findWords(self, words):
        result = []
        for word in words:
            lcase_word = word.lower()
            ch = lcase_word[0]

            for row in ROWS:
                if ch in row:
                    break

            in_row = True
            for ch in lcase_word:
                if not ch in row:
                    in_row = False
                    break

            if in_row:
                result.append(word)
        return result
