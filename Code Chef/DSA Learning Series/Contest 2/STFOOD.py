# "Chef and Street Food"
# Alec Dewulf
# DSA Learning Series - Week 2

# Difficulty: Cakewalk
# Prerequisites: Basic algorithmic design

"""
A very simple problem the only trick was realizing that chef's store added
one to the amount of stores.
"""

import math

test_cases = int(input())
maximum_profits = []
for x in range(test_cases):
    num_food_types = int(input())

    max_profit = 0
    for y in range(num_food_types):
        food_stats = list(map(int, input().split()))
        stores, people, price = food_stats
        
        # the number of stores is greater than the number of people
        if people % (stores + 1) != 0:
            visitors = math.floor(people/(stores + 1))
        else:
            visitors = people/(stores + 1)
        profit = int(price * visitors)

        if profit > max_profit:
            max_profit = profit
            
    maximum_profits.append(max_profit)

# output results
for profit in maximum_profits:
    print(profit)
