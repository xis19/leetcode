import re

def reorderLogFiles(logs: list):
    letter_logs = []
    digit_logs = []
    for log in logs:
        identifier, content = log.split(' ', 1)
        if re.match(r'[0-9 ]+', content):
            digit_logs.append(log)
        else:
            letter_logs.append((content, identifier))
    letter_logs.sort()
    return [
        identifier + ' ' + content
        for content, identifier in letter_logs
    ] + digit_logs
