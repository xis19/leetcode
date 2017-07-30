# The XOR trick:
#   char ch;
#   ch = ch ^ 'm' ^ 'f'
UPDATE salary SET sex = CHAR(ASCII(sex) ^ ASCII('m') ^ ASCII('f'));
