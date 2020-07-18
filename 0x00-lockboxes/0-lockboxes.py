#!/usr/bin/python3


def getKeys(i, keys, boxes):
    """ Try to open boxes depending on the keys """
    if i < len(boxes) - 1 and len(keys) - 1 != len(boxes):
        keys = getKeys(i + 1, updateKeys(keys, boxes, i), boxes)
    else:
        i = len(boxes) - 1
    return keys


def updateKeys(oldKeys, boxes, i):
    """ Open boxes with current keys """
    newKeys = set(oldKeys)
    for i in oldKeys:
        try:
            boxes[i]
        except:
            pass
        else:
            for b in boxes[i]:
                newKeys.add(b)
    return newKeys


def canUnlockAll(boxes):
    """ Unlocks all boxes """
    try:
        myKeys = set(boxes[0])
        if (len(myKeys) == 0):
            return False
    except:
        return False
    h = getKeys(0, myKeys, boxes)
    for i in range(1, len(boxes)):
        if i not in h:
            return False
    return True
