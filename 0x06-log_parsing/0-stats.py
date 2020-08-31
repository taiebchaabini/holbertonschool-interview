#!/usr/bin/python3
import sys
import collections
""" Script that reads stdin line by line and computes metrics. """
i = 0
size = 0
key = ""
metrics = collections.OrderedDict({})
for line in sys.stdin:
    b = [str(x) for x in line.split(' ') if x.strip()]
    key = b[-2]
    if (key in metrics.keys()):
        metrics[key] += 1
    else:
        metrics[key] = 0
    size += int(b[-1])
    i += 1
    if (i == 10):
        print("File size: " + str(size))
        for k in sorted(metrics):
            print(k + ": " + str(metrics[k]))
        i = 0
