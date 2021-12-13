#!/usr/bin/python3


def canUnlockAll(boxes):
    '''
    You have n number of locked boxes in front of you.
    Each box is numbered sequentially from 0 to n - 1
    and each box may contain keys to the other boxes.
    Write a method that determines if all the boxes can be opened.
    '''

    if boxes is None or len(boxes) is 0:
        return False

    list_keys = [0]
    for i in list_keys:
        box = boxes[i]
        for j in box:  # recorro cada caja y anado las keys
            if j < len(boxes) and j not in list_keys:
                list_keys.append(j)
        if len(list_keys) == len(boxes):
            return True
    return False
