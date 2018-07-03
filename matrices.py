#matrixes

import numpy
import string
import random

size = 16

if size%2 == 0:
    limit = size - 2
else:
    limit = size - 1
################

    
a = numpy.zeros([size, size])


#quad1-3: done
for x in range(0, size):
    for y in range(0, size):
        a[x][y] = abs(x-y)-1
        a[y][x] = abs(x-y)-1

#quad4       
for x in range(limit/2+1, size):
    for y in range(limit/2+1, size):
        a[x][y] = (x+y-size)

#quad2      
for x in range(0, limit/2+1):
    for y in range(0, limit/2+1):
        a[x][y] = abs(x+y-size+2)
        
print a

