# 
# Welcome to GDB Online.
# GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
# C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
# Code, Compile, Run and Debug online from anywhere in world.
# 
# 
#!/bin/bash

# Read input from user
read -p "Enter a number: " num

# Function to check if a number is prime
function is_prime {
    if [ $1 -lt 2 ]; then
        return 1
    fi
    for (( i=2; i<=$1/2; i++ )); do
        if [ $(( $1 % $i )) -eq 0 ]; then
            return 1
        fi
    done
    return 0
}

# Check if the number is prime
is_prime $num
if [ $? -eq 0 ]; then
    echo "$num is a prime number."
else
    echo "$num is not a prime number."
fi

# Reverse the number
reverse=0
while [ $num -ne 0 ]; do
    remainder=$(( $num % 10 ))
    reverse=$(( $reverse * 10 + $remainder ))
    num=$(( $num / 10 ))
done

# Print the reverse of the number
echo "The reverse of number is $reverse."
