#!/usr/bin/python
# -*- coding: utf-8 -*-

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

    items = sorted(items, key=lambda y: y.density)
    for item in items:
	if item.weight + weight <= capacity:
		taken[item.index] = 1
		weight += item.weight
		value += item.value




    # prepare the solution in the specified output format
    output_data = str(value) + ' ' + str(0) + '\n'
    output_data += ' '.join(map(str, taken))
    return output_data


import sys

if __name__ == '__main__':
    if len(sys.argv) > 1:
        file_location = sys.argv[1].strip()
        input_data_file = open(file_location, 'r')
        input_data = ''.join(input_data_file.readlines())
        input_data_file.close()
        print solve_it(input_data)
    else:
        print 'This test requires an input file.  Please select one from the data directory. (i.e. python solver.py ./data/ks_4_0)'

