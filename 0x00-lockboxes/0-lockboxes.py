#!/usr/bin/python3


def canUnlockAll(boxes):
    """ Unlocks all boxes """
    visited = [False for v in range(len(boxes))]
    notVisited  = [[] for s in range(len(boxes))]
    stack = [boxes]

    while(len(stack)):
        element = stack[-1]
        stack.pop()
        try:
            if not visited[element]:
                visited[element] = True
            for node in notVisited[element]:
                if not visited[node]:
                    stack.append(node) 
        except:
            pass
    return len(visited) == len(boxes)
