echo Enter two numbers :
read a b
echo Enter 1 for Addition
echo Enter 2 for Subtraction
echo Enter 3 for Multiplication
echo Enter 4 for Division
echo Enter 5 for Exit
read ch
until [ $ch -eq 0 ]
do
    case $ch in
        1) echo $a+$b=`expr $a + $b`;;
        2) echo $a-$b=`expr $a - $b`;;
        3) echo $a\*$b=`expr $a \* $b`;;
        4) if [ $b -eq 0 ]
                then
                    echo Division by 0 cannot be possible
                else
                    echo -n $a/$b= 
                    echo "scale=3;$a/$b"|bc
            fi;;
        5) echo Exiting...
            exit;;
        *) echo Wrong choice
    esac
    echo Enter your choice again :
    read ch
    if [ $ch -ne 5 ]
    then
    echo Enter two numbers :
    read a b
    fi
done
