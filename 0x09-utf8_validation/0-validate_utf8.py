#!/usr/bin/python3
"""This function is used to validated validUTF8"""


def validUTF8(data):
    """ Checks if a given data set represents a valid UTF-8 encoding """
    c = 0
    for n in data:
        m = 0b10000000
        if not c:
            while (m & n):
                c += 1
                m >>= 1
            if c > 4:
                return False
            if c:
                c -= 1
                if c == 0:
                    return False
        elif c > 0:
            if n >> 6 != 2:
                return False
            c -= 1
    return not c
