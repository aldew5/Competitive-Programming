# "Same Parity Summands"
# Codeforces Round 640 
# Difficulty: 1200
# Aldew

t = int(input())

for _ in range(t):
    n, k = map(int, input().split())
    ans = []
    good = False
    p = False
    
    # possible with even
    if n % 2 == 0 and k <= n/2:
        good = True
        x = 0
        while x < k:
            if x + 1 == k:
                if n - sum(ans) > 0 and (n-sum(ans)) % 2 == 0:
                    ans.append(n - sum(ans))
                else:
                    good = False
            else:
                ans.append(2)
            x += 1

        if good:
            p = True
            print('YES')
            print(*ans)

    # possible with odd
    if k <= n and not p:
        good = True
        x = 0
        while x < k:
            # last
            if x + 1 == k:
                # correct
                if n - sum(ans) > 0 and (n-sum(ans)) % 2 == 1:
                    ans.append(abs(n - sum(ans)))
                else:
                    good = False
                    
            else:
                ans.append(1)
            x += 1

        if good:
            p = True
            print("YES")
            print(*ans)

    # nothing got printed
    if not p:
        print('NO')
    
 
            
