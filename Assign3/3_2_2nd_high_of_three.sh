echo Enter 3 numbers :
read a b c
if [ $a -gt $b ]&&[ $a -gt $c ]
    then
        if [ $b -gt $c ]
            then
                echo 2nd highest is : $b
            else
                echo 2nd highest is : $c
        fi
elif [ $b -gt $a ]&&[ $b -gt $c ]
    then
        if [ $a -gt $c ]
            then
                echo 2nd highest is : $a
            else
                echo 2nd highest is : $c
        fi
elif [ $c -gt $a ]&&[ $c -gt $b ]
    then
        if [ $a -gt $b ]
            then
                echo 2nd highest is : $a
            else
                echo 2nd highest is : $b
        fi
fi

