echo Press 1 to copy a file
echo Press 2 to remove a file
echo Press 3 to move a file
echo Press 4 to rename a file 
echo Press 5 to exit
read ch
until [ $ch -eq 0 ]
do 
    case $ch in
        1) echo Enter name of file and new location
        read a b
        cp $a $b;;
        2)echo Enter name of file to be removed
        read a
        rm $a;;
        3)echo Enter name of file to be moved and location
        read a b 
        mv $a $b;;
        4)echo Enter old file name and new file name
        read a b 
        mv $a $b;;
        5)exit;;
        *)echo Wrong choice
    esac
    echo Enter your choice again :
    read ch
done