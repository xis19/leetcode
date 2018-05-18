import collections

DIGIT = ["", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
         "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"]
TENS = ["", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"]
THOUSANDS = collections.OrderedDict({
    1000000000: "Billion",
    1000000: "Million",
    1000: "Thousand",
    1: ""
})


def numberToWords(num):
    if num == 0:
        return "Zero"

    def lessThousand(number):
        result = []

        if number >= 100:
            result.append(DIGIT[number // 100])
            result.append("Hundred")
            number %= 100

        if number >= 20:
            result.append(TENS[number // 10])
            number %= 10

        if number != 0:
            result.append(DIGIT[number])

        return result

    result = []
    for divisor, text in THOUSANDS.items():
        if num >= divisor:
            result.extend(lessThousand(num // divisor))
            if text:
                result.append(text)
            num %= divisor

    return ' '.join(result)
