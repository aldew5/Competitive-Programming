# "Square?"
# Difficulty: 900
# Aldew

t = int(input())
for _ in range(t):
    a, b = map(int, input().split())
    a2, b2 = map(int, input().split())

    if (a + a2) == b and b == b2 or (a + b2) == b and b == a2:
        print('Yes')
    elif (b + b2) == a and a == a2 or (b + a2) == a and a == b2:
        print('Yes')
    else:
        print('No')
