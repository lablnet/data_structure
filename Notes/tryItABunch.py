# set up matplotlib, for plotting stuff.
import matplotlib
import numpy as np
import matplotlib.pyplot as plt
import time
from random import choice
from random import randrange

# This code is grab from https://stanford-cs161.github.io/winter2021-extra/lecture2_sorting-aux.zip
# And modified as needed
# tryItABunch: runs a function a bunch, and times how long it takes.
#
# Input: myFn: a function which takes as input a list of integers
# Output: lists nValues and tValues so that running myFn on a list of length nValues[i] took (on average over numTrials tests) time tValues[i] milliseconds.
#
# Other optional args:
#    - startN: smallest n to test
#    - endN: largest n to test
#    - stepSize: test n's in increments of stepSize between startN and endN
#    - numTrials: for each n tests, do numTrials tests and average them
#    - listMax: the input lists of length n will have values drawn uniformly at random from range(listMax)
#    - algo: Searching or sorting.
def tryItABunch(myFn, startN=10, endN=100, stepSize=10, numTrials=20, listMax = 10, algo = "searching"):
    nValues = []
    tValues = []
    for n in range(startN, endN, stepSize):
        # run myFn several times and average to get a decent idea.
        runtime = 0
        for t in range(numTrials):
            start = time.time()
            lst = [ choice(range(listMax)) for i in range(n) ] # generate a random list of length n

            if algo == "searching":
                random_index = randrange(len(lst))
                item = lst[random_index]
                myFn( lst, item )
            else:
                myFn(lst)
            
            end = time.time()
            runtime += (end - start) * 1000 # measure in milliseconds
        runtime = runtime/numTrials
        nValues.append(n)
        tValues.append(runtime)
    return nValues, tValues
