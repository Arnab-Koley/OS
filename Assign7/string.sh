echo Enter a string :
read str
v=0
uc=0
lc=0
d=0
sp=0
len=`expr length "$str"`
i=1
while [ $i -le $len ]
do
    ch=`expr substr "$str" $i 1`
    case $ch in
        a|e|i|o|u|A|E|I|O|U) v=`expr $v + 1`;;
    esac
    case $ch in
        [A-Z]) uc=`expr $uc + 1`;;
        [a-z]) lc=`expr $lc + 1`;;
        [0-9]) d=`expr $d + 1`;;
        *) sp=`expr $sp + 1`;;
    esac
    let i=i+1
done
echo String Length = $len
echo Number of vowels = $v
echo Number of upper case letters = $uc
echo Number of lower case letters = $lc
echo Number of digits = $d
echo Number of special characters = $sp




# Enter a string :
# Arnab@123 456#
# String Length = 14
# Number of vowels = 2
# Number of upper case letters = 1
# Number of lower case letters = 4
# Number of digits = 6
# Number of special characters = 3