#!/usr/bin/python3
# #Solving algorithm

def canUnlockAll(boxes):
    '''
    You have n number of locked boxes in front of you.
    Each box is numbered sequentially from 0 to n - 1 and each box may contain keys to the other boxes.
    Write a method that determines if all the boxes can be opened.
    '''
    

    if boxes is None or len(boxes) is 0:
        return False

    status = ["T"]

    for box in range(1, len(boxes)):
        status.append("F")

    for box in range(0, len(boxes)):
        if (status[box] is "T" or box is 0):
            for key in boxes[box]:
                if int(key) < len(boxes) and status[key] is "F":
                    for k in boxes[key]:
                        if k < len(boxes):
                            status[k] = "T"
                if key < len(boxes):
                    status[key] = "T"

    if "F" in status:
        return False
    return True




