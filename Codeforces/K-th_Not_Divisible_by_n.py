# "K-th Not Divisible by n"
# Codeforces Round 640
# Difficulty: 1200
# Aldew

"""
Think of the numbers n is not divisible by as a sequence {1, 2, ..., n-1}
where each number in the sequence increases by n each iteration.
"""

import math

t = int(input())
for _ in range(t):
    n, k = map(int, input().split())

    # end of the list
    if (k % (n-1)) == 0:
        ans = n -1
    else:
        ans = k % (n-1)
    
    # times num cycles
    ans += (math.ceil(k/(n-1))-1) *n 


    print(ans)
