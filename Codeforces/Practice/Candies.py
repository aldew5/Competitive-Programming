#"Candies"
# Aldew
# Difficulty: 900

"""
You just need to find the first sum of powers of two that divide n.
x is just n/(the sum).
"""

t = int(input())
for _ in range(t):
    num_wrap = int(input())

    c = 3
    p = 2
    while True:
        if num_wrap % c == 0:
            break
        else:
            c += 2**p
            p += 1


    print(int(num_wrap/c))
