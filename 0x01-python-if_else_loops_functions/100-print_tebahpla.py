#!/usr/bin/python3
for x in range(ord('z'), ord('a')-1,-1):
    if x % 2 != 0:
        print("{}".format(chr(x-32)),end="")
    else:
        print(f"{chr(x)}",end="")
