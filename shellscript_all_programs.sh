# calculator

# !/bin/bash

# Take user Input
echo "Enter Two numbers : "
read a
read b

# Input type of operation
echo "Enter Choice :"
echo "1. Addition"
echo "2. Subtraction"
echo "3. Multiplication"
echo "4. Division"
read ch

# Switch Case to perform
# calculator operations
case $ch in
1)res=`echo $a + $b | bc`
;;
2)res=`echo $a - $b | bc`
;;
3)res=`echo $a \* $b | bc`
;;
4)res=`echo "scale=2; $a / $b" | bc`
;;
esac
echo "Result : $res"

#Revesrse String

#!/bin/bash
echo "Enter a string: "
read s

strlen=${#s}
for (( i=$strlen-1; i>=0; i-- ));
do
    revstr=$revstr${s:$i:1}
done
echo "Original String : $s"
echo "Reversed String : $revstr"

# Linux commands using switch case

echo -e  "1.List of files\n
2.No. of processes\n
3.Today's date\n
4.Logged users\n
5.exit\n"
echo "Enter your choice"
read ch
case $ch in
1)ls ;;
2)ps ;;
3)date ;;
4)who ;;
5)exit ;;
*) echo "Wrong choice, enter again“
esac


# Pyramid of star

#!/bin/bash
for (( i=1; i<=5; i++ ))
do
 for (( j=1; j<=i; j++ )) 
 do 
        echo -n "*" 
done
 echo 
 done

# factorial of number

#!/bin/bash
# Recursive factorial function

factorial()
{
    product=$1
           
    # Defining a function to calculate factorial using recursion
    if((product <= 2)); then
        echo $product
    else
        f=$((product -1))
        
# Recursive call

f=$(factorial $f)
f=$((f*product))
echo $f
fi
}

# main program
# reading the input from user
echo "Enter the number:"   
read num

# defining a special case for 0! = 1
if((num == 0)); then   
echo 1
else
#calling the function
factorial $num
fi

# Array sorting 

# Sorting the array in Bash 
# using Bubble sort

# Static input of Array
arr=(10 8 20 100 12)

echo "Array in original order"
echo ${arr[*]}

# Performing Bubble sort 
for ((i = 0; i<5; i++))
do
    
    for((j = 0; j<5-i-1; j++))
    do
    
        if [ ${arr[j]} -gt ${arr[$((j+1))]} ]
        then
            # swap
            temp=${arr[j]}
            arr[$j]=${arr[$((j+1))]}  
            arr[$((j+1))]=$temp
        fi
    done
done

echo "Array in sorted order :"
echo ${arr[*]}
