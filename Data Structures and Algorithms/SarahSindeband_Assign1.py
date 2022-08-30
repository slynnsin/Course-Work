# COP 3410- Assignment 1
# Sarah Sindeband
# Pg. 51, choose 8 exercises, python functions
# function calls can accumulate inside a main function
# main functtion will be used for just the purpose of running the functions
# 1/28/22

# pg.73


# function definitions

# Exercise 1.1
def is_multiple(n, m):
    leftover = m % n
    if leftover == 0:
        print(n, "is a multiple of", m)
        return True
    else:
        print(n, "is not a multiple of", m)
        return False

# Exercise 1.2
def is_even(k):
    if k % 2 == 0:
        print(k, "is an even number")
        return True
    else:
        print(k, "is not an even number")
        return False

# Exercise 1.3
def minmax():
    data = input("Enter some data: ")
    min = max = data[0]
    for j in data:
        if j > max:
            max = j
        elif j < min:
            min = j
    print("The minimum is", min, "and the maximum is", max)
    return min, max
# Exercide 1.4
def fun(num):
    sum_squares = 0
    count = num
    while (num > 0) and (count > 0):
        squares = (count - 1)**2
        sum_squares += squares
        count -=1
    print("The sum of squares for the numbers less than", num, "is", sum_squares)
    return sum_squares

# Exercise 1.5
def built_in_fun(built):
    print(sum([i**2 for i in range(built)]))

# Exercide 1.6
def odds_only(num2):
    sum_squares2 = 0
    if num2 % 2 == 0:
        num2 +=1
    count2 = num2
    built2 = num2 - 2
    while (num2 > 1):
        squares2 = (num2 - 2)**2
        sum_squares2 += squares2
        num2 -=2
    print("The sum of squares of the odd numbers less than", built2, "is", sum_squares2)
    return sum_squares2

# Exercise 1.7
def built_in_fun2(built2):
    print(sum([i**2 for i in range(1, built2, 2)]))

# Exercise 1.11
def list_fun():
    new_list = [2**k for k in range(0,9)]
    print("\n", new_list)


# define main function
def main():
    # Exercise 1.1
    print("\nReinforcement Exercise 1.1")
    n = int(input("Please enter an integer: "))
    m = int(input("Please enter another integer: "))
    is_multiple(n, m)
    # Exercise 1.2
    print("\nReinforcement Exercise 1.2")
    k = int(input("Please enter an integer: "))
    is_even(k)
    # Exercise 1.3
    print("\nReinforcement Exercise 1.3")
    minmax()
    # Exercide 1.4
    print("\nReinforcement Exercise 1.4")
    num = int(input("Enter a number: "))
    built = num
    fun(num)
    # Exercise 1.5
    print("\nReinforcement Exercise 1.5")
    built_in_fun(built)
    # Exercise 1.6
    print("\nReinforcement Exercise 1.6")
    num2 = int(input("Enter another number: "))
    built2 = num2
    odds_only(num2)
    # Exercise 1.7
    print("\nReinforcement Exercise 1.7")
    built_in_fun2(built2)
    # Exercise 1.11
    list_fun()



# call the main function
main() 
