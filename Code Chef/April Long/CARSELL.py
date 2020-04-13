# "Sell All the Cars"
# Alec Dewulf
# April Long 2020

# Difficulty: Simple
# Concepts: Greedy

"""
EXPLANATION

The only thing really to figure out was that it is better to sell
the most profitable cars first. All the cars lose one off of their values
until they are sold or are valued at zero so selling the most valuable cars
first minimizes this loss.
"""

num_cases = int(input())

profits = []
for x in range(num_cases):
    profit = 0
    
    num_cars = int(input())
    
    # car input
    cars = sorted(list(map(int, input().split())))
        
    n, num_years = -1, 0
    while n >= -1 * len(cars):
        # compute the final value for the car
        if cars[n] - (num_years) >= 0:
            value = cars[n] - (num_years)
        # value would have been negative
        else:
            value = 0

        # don't sell a worthless car
        if value == 0:
            pass
        else:
            profit += value
            num_years += 1
        n -= 1
    
    profits.append(profit)
    x += 1

    
# output resutls
for p in profits:
    print(p % (10**9 + 7))
    
    
            
        
