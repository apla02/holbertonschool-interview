#!/usr/bin/python3


"""
method that calculates the fewest number of operations needed to result
in exactly n H characters in the file.
"""


def minOperations(n):
    """
    Finds the min operations
    """
    answer = 0
    x = 2
    while n > 1:
        while n % x == 0:
            answer = answer + x
            n = n / x
        x = x + 1
    return answer
