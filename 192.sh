#! /bin/bash
# cat the text | replace all newline/space into newline | remove empty lines |
# sort | unique with count | reverse sort | reorder the output
cat words.txt | sed 's/[ \n]\+/\n/g' | sed '/^$/d' | sort | uniq -c | sort -r | awk '{ printf "%s %s\n",$2,$1 }'

# NOTE: The two seds can be replaced by a single tr -s ' ' '\n'
