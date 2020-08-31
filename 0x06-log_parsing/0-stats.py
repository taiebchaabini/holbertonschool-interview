#!/usr/bin/python3
import sys


i = 0
size = 0
key = ""
metrics = {}
def print_stuff():
    print("File size: " + str(size))
    for k in sorted(metrics):
        print(k + ": " + str(metrics[k]))
for line in sys.stdin:
    b = [str(x) for x in line.rstrip().split(' ') if x.strip()]
    key = b[-2]
    if (key in metrics.keys()):
        metrics[key] += 1
    else:
        metrics[key] = 1
    size += int(b[-1])
    i += 1
    if (i == 10):
        print_stuff()
        i = 0
