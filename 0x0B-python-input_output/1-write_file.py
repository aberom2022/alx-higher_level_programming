#!/usr/bin/python3
def write_file(filename="", text=""):
    cont = 0
    with open(filename, 'r') as f:
        for li in f:
            cont += 1
    return cont 
