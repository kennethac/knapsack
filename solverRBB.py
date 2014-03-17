#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys
import os
from subprocess import Popen, PIPE

from collections import namedtuple
Item = namedtuple("Item", ['index', 'value', 'weight','density'])
NodeInfo = namedtuple("NodeInfo", ['index','value','room','estimate'])
Node = namedtuple("Node", ['index','info','last','left','right'])

def solve_it(input_data):
    # Modify this code to run your optimization algorithm

    # My vars:
    Ktable = []

    # parse the input
    lines = input_data.split('\n')

    firstLine = lines[0].split()
    item_count = int(firstLine[0])
    capacity = int(firstLine[1])

    Ktable = [[0]*(capacity+1)]
#    print Ktable
    items = []
    maxDensity = 0.0


    for i in range(1, item_count+1):
        line = lines[i]
        parts = line.split()
	density = float(parts[0])/float(parts[1])
	maxDensity = max(maxDensity,density)
        items.append(Item(i-1, int(parts[0]), int(parts[1]), density))


    value = 0
    weight = 0
    taken = [0]*len(items)

    items = sorted(items, key=lambda y: y.density) # sort items by density

    maxValue = 0
    weightHolder = capacity
    for item in items:
#	print maxValue
#	print item.index
	if weightHolder - item.weight >= 0:
		weightHolder -= item.weight
		maxValue += item.value
	else:
		frac = (float(item.value) - float(weightHolder)) / float(item.value)
		fracVal = frac * float(item.value)
	#	print fracVal
		maxValue += fracVal
		break
#    print maxValue
 #   quit()

    tmp_file_name = 'tmp.data'
    tmp_file = open(tmp_file_name, 'w')
    tmp_file.write(str(maxValue))
    tmp_file.write("\n")
    tmp_file.write(str(capacity))
    tmp_file.write("\n")
    tmp_file.write(str(len(items)))
    tmp_file.write("\n")
    for item in items:
	itemString = str(item.index)+" "+str(item.value)+" "+str(item.weight)+" "+str(item.density)
	tmp_file.write(itemString)
	tmp_file.write("\n")
    tmp_file.close()

 
# Runs the command ./RBB tmp.data
    exe  = "/Users/Kenneth/mooc/DiscreteOptimization/Intro/knapsack/RBB"
    process = Popen([exe,tmp_file_name],stdout=PIPE)
    (stdout,stderr) = process.communicate()

    # removes the temporary file#
#    os.remove(tmp_file_name)

    print stdout
    quit()
    #sys.exit()

    #sys.quit()
    # prepare the solution in the specified output format
    output_data = str(value) + ' ' + str(0) + '\n'
    output_data += ' '.join(map(str, taken))
    return output_data



if __name__ == '__main__':
    if len(sys.argv) > 1:
        file_location = sys.argv[1].strip()
        input_data_file = open(file_location, 'r')
        input_data = ''.join(input_data_file.readlines())
        input_data_file.close()
        print solve_it(input_data)
    else:
        print 'This test requires an input file.  Please select one from the data directory. (i.e. python solver.py ./data/ks_4_0)'

