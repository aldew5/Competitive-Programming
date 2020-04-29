# "Alternating Subsequence"
# Aldew
# Difficulty: 1200

"""
To find max length just add 1 to k everytime there is an alternating sign.

Choose the greatest positive number between each negative number and the greatest
negative number
"""

t = int(input())

for _ in range(t):
    n = int(input())
    seq = list(map(int, input().split()))

    s = 0
    prev_t, poss = None, []
    for i in seq:
        if i < 0:
            t = 'n'
        else:
            t = 'p'

        # the type is the same so these are all options
        if prev_t == None or t == prev_t:
            poss.append(i)
        # type change so have to increment s by greatest amount
        else:
            s += max(poss)
            poss = [i]
        prev_t = t

    # add the max of the final list of poss
    s += max(poss)
        
    print(s)
