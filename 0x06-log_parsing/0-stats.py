#!/usr/bin/python3
import sys
import collections
import signal
""" Script that reads stdin line by line and computes metrics. """

i = 0
size = 0
key = ""
metrics = collections.OrderedDict({})


def print_stuff():
    """ Prints file isze + metrics """
    print("File size: " + str(size))
    for k in sorted(metrics):
        print(k + ": " + str(metrics[k]))


def signal_handler(sig, frame):
    """ Check if ctrl + c is pressed then prints metrics """
    print_stuff()
    sys.exit(0)


signal.signal(signal.SIGINT, signal_handler)
for line in sys.stdin:
    b = [str(x) for x in line.split(' ') if x.strip()]
    key = b[-2]
    if (key in metrics.keys()):
        metrics[key] += 1
    else:
        if key in [200, 301, 400, 401, 403, 404, 405, 500]:
            metrics[key] = 1
    size += int(b[-1])
    i += 1
    if (i == 10):
        print_stuff()
        i = 0
