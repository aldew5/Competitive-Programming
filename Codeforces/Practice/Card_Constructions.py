# "Card Constructions"
# Difficulty: 1100
# Aldew

"""
2, 7, 15

increase by 5 then 3 more each time (5, 8, 11 ...)
"""

t = int(input())
for _ in range(t):
    n = int(input())
    
    num_pyramid = 0

    while n >= 2:
        c = 2
        i = 5
        # none
        if n - 2 < 0:
            break
        else:
            while c < n:
                c += i

                if c > n:
                    c -= i
                    break
                else:
                    i += 3
            
            num_pyramid += 1
            n -= c

    print(num_pyramid)
        
