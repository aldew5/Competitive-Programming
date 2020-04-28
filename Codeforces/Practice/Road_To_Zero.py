# "Road to Zero"
# Aldew
# Difficulty: 1100

"""
If decreasing by two is cheaper do that until it's no longer
possible then decrease by one.
"""

t = int(input())

for _ in range(t):
    x, y = map(int, input().split())
    a, b = map(int, input().split())

    cost = 0
    # cheaper to just decrease them both by one
    if 2*a < b:
        cost = x*a + a*y

    else:
        if x < y:
            # amount of double decreases plus left over 
            cost = x*b + (y-x)*a
        elif y < x:
            cost = y*b + (x-y)*a
        # equal
        else:
            cost = b*x

    print(cost)
            
        
        
