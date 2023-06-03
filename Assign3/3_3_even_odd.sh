echo Enter 2 numbers :
read a b
if [ $((a%2)) -eq 0 ]
    then
        if [ $((b%2)) -eq 0 ]
            then
                echo $a and $b both are even
            else
                echo $a is even but $b is odd
        fi
    else    
        if [ $((b%2)) -eq 0 ]
            then
                echo $a is odd but $b is even
            else
                echo $a and $b both are odd
        fi
fi