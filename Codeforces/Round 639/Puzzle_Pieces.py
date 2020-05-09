# "Puzzle "Pieces"
# Codeforces Round # 639: Problem A
# Difficulty: 800

t = int(input())

for _ in range(t):
    n, m = map(int, input().split())

    # one row
    if n == 1 or m == 1:
        print('YES')
    # 2x2
    elif n == 2 and m == 2:
        print('YES')
    else:
        print('NO')


    
