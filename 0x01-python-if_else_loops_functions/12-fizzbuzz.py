#!/usr/bin/python3
def fizzbuzz():
    for x in range(1, 101):


        """check for multiples of 3 and 5 and replace with fizzbuzz"""
        if x % 3 == 0 and x % 5 == 0:
            print("FizzBuzz ",end="")
        elif x % 3 == 0:
            print("Fizz ", end="")
        elif x % 5 == 0:
            print("Buzz ", end ="")
        else:
            print("{}".format(x),end=" ")
