def palindromePairs(words):
    result = []

    # We first build a word hash
    word_hash = dict()
    for index, word in enumerate(words):
        word_hash[word] = index

    # Then we go back to the words
    for index, word in enumerate(words):
        # Try to build the palindrome with itself
        word_length = len(word)

        # We do not want to cover full word, it will be considered in the
        # next part.
        for i in range(0, word_length):
            # abcd -> abcdcba style, note the [:i] is [start, end) style
            l_rev = word[:i][::-1]
            # abcd -> dcbabcd style, note here the HEAD is exclusive, i.e.
            # (start, end] style
            r_rev = word[i + 1:][::-1]

            if l_rev in word_hash and (word + l_rev) == (word + l_rev)[::-1]:
                result.append([index, word_hash[l_rev]])
            if r_rev in word_hash and (r_rev + word) == (r_rev + word)[::-1]:
                result.append([word_hash[r_rev], index])

        # Finally, reverse the word. It will definitively generate
        # a palindrome
        rev_word = word[::-1]
        if rev_word in word_hash and rev_word != word:
            # We only put it on one part, since when we revisit
            # the reversed word, we will do this again.
            result.append([word_hash[rev_word], index])

    return result


print(palindromePairs(['a', '']))
print(palindromePairs(["abcd", "dcba", "lls", "s", "sssll"]))
