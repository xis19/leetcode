# 1. use sed
sed -n '10p' file.txt
# 2. use awk
awk 'NR == 10 { print $0 }' file.txt
# 3. use head/tail
tail -n+10 file.txt|head -n1
