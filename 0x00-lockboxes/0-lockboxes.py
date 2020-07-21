#!/usr/bin/python3


def canUnlockAll(boxes):
    """ Unlocks all boxes """
    try:
        myKeys = list(boxes[0])
    except:
        return False
    c = 0
    while(1):
        c += 1
        if (c == len(boxes)):
            break
        for i in myKeys:
            try:
                boxes[i]
            except:
                pass
            else:
                for b in boxes[i]:
                    if b not in myKeys and b != 0:
                        myKeys.append(b)
    for i in range(1, len(boxes)):
        if i not in myKeys:
            return False
    return True
