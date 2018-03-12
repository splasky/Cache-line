#! /usr/bin/python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
# Last modified: 2018-03-12 13:49:55

from matplotlib import pyplot
with open("result.txt") as f:
    data = f.readlines()

data = list(map(float, data))

pyplot.plot(data)
pyplot.grid()
pyplot.show()
