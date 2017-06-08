import collections
import os.path

def findDuplicate(paths):
    duplicates = collections.defaultdict(list)

    for path in paths:
        base_path, files = path.split(' ', 1)
        file_contents = files.split(' ')
        for f in file_contents:
            name, content = f.split('(')
            duplicates[content].append(os.path.join(base_path, name))

    result = []
    for k, v in duplicates.items():
        if len(v) > 1:
            result.append(v)

    return result
