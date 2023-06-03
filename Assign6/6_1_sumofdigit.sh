
function sum(){
  n=$1
  sum=0
  while [ $n -ne 0 ]
  do
    r=$(( $n % 10 ))
    n=$(( $n / 10 ))
    sum=$(( $sum + $r ))
  done
  echo "The sum of all digits of $1=$sum"
}

n=$1
n1=$n
sum $n1

