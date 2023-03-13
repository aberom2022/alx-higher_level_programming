#!/usr/bin/python3
def no_c(my_string):
    new_sentence = my_string.translate({ord('c') : None})
    new_sentence = my_string.translate({ord('C') : None})
    return new_sentence

print(no_c("The letter comes nothing"))
