class Solution:
    def isValid(self, code: str) -> bool:
        token_stack = []
        # To avoid situations like <A></A><B></B> -- the token stack could be only cleared once
        token_stack_cleared = False
        LEN = len(code)
        iterator = 0

        while iterator < LEN:
            if code[iterator] != '<':
                # Anything must be inside tags
                print(token_stack)
                if len(token_stack) == 0:
                    return False

                iterator += 1
                continue

            if code[iterator:].startswith('<![CDATA['):
                # This must stay in tags
                if len(token_stack) == 0:
                    return False

                end_pos = code[iterator:].find(']]>') + iterator
                if end_pos == -1:
                    # Unterminating CDATA
                    return False
                iterator = end_pos + 3
                continue

            end_tag_pos = code[iterator:].find('>') + iterator
            if end_tag_pos == -1:
                # Unterminating tag
                return False

            tag_body = code[iterator + 1:end_tag_pos]
            close_tag = False
            if tag_body.startswith('/'):
                close_tag = True
                tag_body = tag_body[1:]

            # Tag name must be all upper, length between 1 and 9
            if (tag_body.upper() != tag_body
                    or any(ch > 'Z' or ch < 'A' for ch in tag_body)
                    or len(tag_body) > 9
                    or len(tag_body) < 1):
                return False

            if close_tag:
                if len(token_stack) == 0 or token_stack[-1] != tag_body:
                    # Tag mismatch
                    return False
                token_stack.pop()
                if len(token_stack) == 0:
                    token_stack_cleared = True
            else:
                # We have already finished a set of tag tree
                # The code must be wrapped in ONE valid closed tag
                if token_stack_cleared:
                    return False
                token_stack.append(tag_body)

            iterator = end_tag_pos + 1

        return len(token_stack) == 0
