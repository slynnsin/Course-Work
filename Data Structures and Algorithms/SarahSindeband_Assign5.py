# Sarah Sindeband
# COP 3410
# Assignment 5
# 03/14/22
# Each problem solved in the form of a function & test all functions in the program


import random

# 1.
def sum_data(data, n):
    print("\n\n1. Compute the sum of all numbers in an n x n data set, represented as a list of lists.")
    print("Data set:", data)
    data_set = [data] * n # similar to function from lecture 3/2/22
    print("List of lists:\n",data_set)
    i = 0
    data_sum = 0
    while i < n:
        data_sum += data[i]
        i+=1
    print("Sum of all numbers in the list of lists:", data_sum * n)
    

# 2.
def built_in_sum_data(data, n):
    print("""\n\n2. Use the built-in sum function combined with Python’s comprehension syntax to computethe sum of all numbers in an n×n data set, represented as a list of lists.""")
    print("Data set:", data)
    data_set = [data] * n
    print("List of lists:\n",data_set)
    built_in = sum(data * n)
    print("Sum of all numbers from the built in sum fuction:", built_in)

# 3.
def new_shuffle(n, data):
    print("""\n\n3. The shuffle method, supported by the random module, takes a Python list, and rearranges it so that every possible ordering is equally likely. Implement your own version of such a function. You may rely on the randrange(n) function of the random module, which returns a random number between 0 and n−1 inclusive.""")
    rand_data = random.randrange(n)
    print("A random number from the data set:", rand_data)

# 4.
def function(same, different):
    print ("\n\n4. Let B be an array of size n ≥ 6 containing integers from 1 to n, inclusive, with exactly five repeated. Write a function that finds the unique value in the array.")
    B = [2, 2, 2, 3, 2, 2]
    i = 0
    while i+1 < len(B):
        if B[i] != B[i+1]:
            different = B[i]
            i += 1
        else:
            i +=1
    print("The index with the unique value is:", different)
        
def main():
    data = [0, 1, 2, 3, 4]
    n = len(data)
    sum_data(data, n)
    built_in_sum_data(data, n)
    new_shuffle(n, data)
    different = 0
    same = 0
    function(same, different)


main()

