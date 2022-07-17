# Python code to demonstrate the working of 
# accumulate()
import itertools
import operator


# initialize list 1
lst = [1, 4, 5, 7]


### Part I. Prints the successive summation of elements
print("The sum after each iteraction is:")
print( list(itertools.accumulate(lst)) )
print('*' * 40)


### Part II. Prints the successive multiokication of elements
print("The production after each iteration is:")
print( list(itertools.accumulate(lst, operator.mul)) )