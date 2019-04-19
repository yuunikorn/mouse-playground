import numpy
import string
import random
from matrices import *
#from compass import *
#from IRsensor import *


def initCoord(matrix, offset):
    print "start position at ("+ str(matrix[0][0] + offset) + " , " + str(0) + ")"
    return [matrix[0][0] + offset,0]


def cellValidity(currCoord, limit):
    if  0 <= currCoord[0] <= limit:
        if  0 <= currCoord[1] <= limit:
            #print 1
            return 1
    #print 0
    return 0



def NeighboringCoordinatePriority(currCoord, currCounter):
    print "Our current coordinated are "+ currCoord + " and the direction faces " + directionDecoder(currCounter) 
    direction = currCounter % 4
    
    if direction == 0: #direction == north:
        leftCoord = 1
        centerCoord =1
        rightCoord = 1

        return 1        
        
    #
    #
    #
    #elif #direction == east
    #
    #
    #
    #
    #
    #
    #elif #direction == south
    #
    #
    #
    #
    #else #direction == west
    #
    #
    #
    #
    #
    #
    #
    #
    #
    #
    #
    #



#visited = 0

#a = genMatrix(9)
#print currCoordinates()


#def sensorval():
    #walls = IRsensorCollect() #[left, center, right]
    #print 1
    



#sensorval()


