def removeSubfoldersSlow(folder: List[str]) -> List[str]:
    folder.sort()

    short = set()

    # for item in folder:
    #     for parent in short:
    #         if item.startswith(parent + '/'):
    #             break
    #     else:
    #         short.add(item)

    for item in folder:
        split = item.split('/')
        for x in range(0, len(split)):
            # This could be further optimized...
            if '/'.join(split[0:x]) in short:
                break
        else:
            short.add(item)

    return short
