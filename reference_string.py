#!/usr/bin/env python3
import random as rd


def random(min, max):
    return rd.randint(min, max)


def main(args):
    if (len(args)!=4):
        print("usage:\n./reference_string.py [min] [max] [length]\n    types             <int> <int> <int>")
    else:
        min = int(args[1])
        max = int(args[2])
        length = int(args[3])
        ref = ""
        for value in range(0,length-1):
            val = random(min,max)
            ref += str(val) + ","
        ref += str(random(min,max))
    print(ref)

if __name__ == '__main__':
    import sys
    main(sys.argv)
