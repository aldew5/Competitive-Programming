# "Sum of Round Numbers"
# Codeforces Round 640
# Aldew

t = int(input())

for _ in range(t):
    n = input()
    ans = []

    zeros = len(n) - 1
    for i in n:
        if i != '0':
            ans.append(i + '0'*zeros)
        zeros -= 1

    print(len(ans))
    print(*ans)
