# "Lapindromes"
# Alec Dewulf
# DSA Learning Series

# Difficulty: Cakewalk
# Concepts: Palindromes

"""
Simply realized that if the list is odd in length the middle
can just be taken out and the remaining sides compared.
"""

import math

test_cases = int(input())
ans = []
for t in range(test_cases):
    lap = list(input())

    # if odd delete the middle number
    if len(lap) % 2 != 0:
        del lap[math.floor(len(lap)/2)]

    middle = int(len(lap) / 2)
    
    first, last = '', ''
    for n in range(0, middle):
        first += lap[n]

    for n in range(middle, len(lap)):
        last += lap[n]
        
    # same 
    if sorted(last) == sorted(first):
        ans.append('YES')
    # not
    else:
        ans.append('NO')


for a in ans:
    print(a)
