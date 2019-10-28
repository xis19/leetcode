def reverseParentheses(self, s: str) -> str:
    def run():
        word_stack = ['']

        for char in s:
            if char == '(':
                word_stack.append('')
            elif char == ')':
                word = word_stack[-1]
                word_stack.pop()
                word_stack[-1] += word[::-1]
            else:
                word_stack[-1] += char

        return word_stack[-1]

    return run()
