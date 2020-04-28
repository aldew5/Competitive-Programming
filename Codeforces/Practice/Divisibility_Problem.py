# "Divisibility Problem"
# Aldew
# Difficulty: 700

import math

t = int(input())

# a must be a multiple of b
for _ in range(t):
    a, b = map(int, input().split())

    # the first correct solution is just b
    if a <= b:
        num_moves = b - a
    # difference bewteen a and closest multiple of b
    else:
        c = math.ceil(a/b)
        # distance to the closest multiple
        num_moves = abs(b*c - a)


    print(num_moves)
