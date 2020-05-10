# "Kana and Dragon Quest game"
# Difficulty: 900
# Aldew

import math

def void_absorption(h):
    return math.floor(h/2) + 10

t = int(input())
for _ in range(t):
    x, va, ls = map(int, input().split())

    while va > 0 and void_absorption(x) < x:
        x = void_absorption(x)
        va -= 1

    x -= 10*ls

    if x > 0:
        print('NO')
    else:
        print('YES')
        
