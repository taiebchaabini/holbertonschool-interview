#!/usr/bin/python3
"""
Prime Game
"""


def isPrimeNumber(n):
    divider = 0
    if (n <= 1):
        return False
    for i in range(n, 0, -1):
        if (n % i == 0):
            divider += 1
    if (divider != 2):
        return False
    return True


def isWinner(x, nums):
    """
    Prime Game
    """
    if (x <= 0 or not nums):
        return None
    roundScore = {'Maria': 0, 'Ben': 0}
    score = {'Maria': 0, 'Ben': 0}
    playersName = ['Maria', 'Ben']
    roundNumbers = []
    selectedNumber = 2
    playerNB = 0
    currentPlayer = 0
    foundPrime = False
    for gRound in range(x):
        roundScore = {'Maria': 0, 'Ben': 0}
        roundNumbers = list(range(1, nums[gRound] + 1))
        foundPrime = False
        if (len(roundNumbers) == 1):
            roundScore[playersName[(playerNB + 1) % 2]] += 1
            
        for i in range(len(roundNumbers) + 1):
            if (isPrimeNumber(i)):
                for b in range(i + 1, len(roundNumbers) + 1):
                    if (b % i == 0):
                        del roundNumbers[roundNumbers.index(b)]
                del roundNumbers[roundNumbers.index(i)]
                playerNB += 1
                roundScore[playersName[(playerNB + 1) % 2]] += 1
                

        if (roundScore[playersName[0]] == roundScore[playersName[1]]):
            roundScore[playersName[(playerNB + 1) % 2]] += 1
            
        if (roundScore[playersName[0]] > roundScore[playersName[1]]):
            score[playersName[0]] += 1
        else:
            score[playersName[1]] += 1
    
    if (score[playersName[0]] == score[playersName[1]]):
            playerNB += 1
            score[playersName[(playerNB + 1) % 2]] += 1
            
    if (score[playersName[0]] > score[playersName[1]]):
        return playersName[0]
    else:
        return playersName[1]

    return None
