import numpy
import string
import random
from matrices import *
from coordinates import *
from compass import *

size = int(raw_input("size of matrix: "))
limit = MatrixLimits(size) + MatrixOffset(size)

matrix = genMatrix(size)

matrix[limit][0] = 88
print matrix

currCoord = initCoord(matrix, MatrixOffset(size))
print currCoord[0]
print currCoord[1]

currCounter = initDirectionCounter(size)

directionDecoder(currCounter)

cellValidity(currCoord, limit)
