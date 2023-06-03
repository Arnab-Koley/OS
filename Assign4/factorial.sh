echo Enter a number :
read n
fact=1

for((i=1;i<=n;i++))
do
    fact=$((fact * i))
done
echo Factorial of $n using for loop: $fact

i=1
while [ $i -le $n ]
do
    fact=$((fact * i))
    i=$((i + 1))
done
echo Factorial of $n using while loop: $fact
