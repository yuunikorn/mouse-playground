import numpy
import string
import random
from matrices import *


def initDirectionCounter(size):
    counter = size * size * 4 #just to be safe
    print "Initialized direction counter: " + str(counter)
    return counter



def directionDecoder(currCounter):
    counter = currCounter % 4
    if counter == 0:
        print 'North'
    elif counter == 1:
        print 'East'
    elif counter == 2:
        print 'South'
    elif counter == 3:
        print 'West'
    else:
        print NULL 


#directionality, north = 0, east = 1, south = 2, west = 3
#directionality = 0

#def currDirection(directionCounter, directionality):

    #if right turn
        #directionCounter = directionCounter + 1

    #if left turn
        #directionCounter = directionCounter - 1 

    #else straight, 0

    #directionVal = directionCounter % 4

    #switch directionVal
    #
    #if 0, direction = North
    #if 1, direction = East
    #if 2, direction = South
    #if 3, direction = West

    #return direction
