#matrixes

import numpy
import string
import random

size = 8
a = numpy.zeros([size, size])

if size%2 == 0:
    limit = size - 2
    decrement = 0
else:
    limit = size - 1
    decrement = 1
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

print a
print a[limit/2][limit/2]

