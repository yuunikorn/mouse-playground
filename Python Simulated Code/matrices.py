#matrixes

import numpy
import string
import random

def genMatrix(size):
    a = numpy.zeros([size, size])

    if size%2 == 0:
        limit = size - 2
        decrement = 0
        increment = 1
    else:
        limit = size - 1
        decrement = 1
        increment = 0
    ################

    #quad1-3: done
    for x in range(0, size):
        for y in range(0, size):
            a[x][y] = abs(x-y)-1 + decrement
            a[y][x] = abs(x-y)-1 + decrement

    #quad2      
    for x in range(0, limit/2 + 1):
        for y in range(0, limit/2 +1):
            a[x][y] = abs(x+y-limit) 

    #quad4       
    for x in range(limit/2 + 1, size):
        for y in range(limit/2 +1, size):
            a[x][y] = (x+y-size) + decrement

    return a


def MatrixLimits(size):
    if size%2 == 0:
        return size - 2
    else:
        return size - 1
    
def MatrixOffset(size):
    if size%2 == 0:
        return 1
    else:
        return 0
