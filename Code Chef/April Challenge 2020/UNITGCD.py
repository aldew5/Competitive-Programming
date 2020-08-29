# "Unit GCD"
# Alec Dewulf
# April Long 2020

# Difficulty: Simple
# Concepts: Pigeonhole principle

"""
EXPLANATION

This problem becomes very simple if you notice that there are n//2 even numbers
and by pigeonhole principle each must be on a different day (they all share a
factor of two). Therefore there must be n//2 days.

- If n is even each day will have two numbers a at i and a at i + 1.
- If n is odd each day will have two numbers except for the last day
  which will have a at n-2 a at n-1 and a at n.
- If n is one there will be one day with just one.

"""

num_tests = int(input())
solutions = []

for y in range(num_tests):
    num_pages = int(input())


    # handle one page
    if num_pages == 1:
        min_days = 1
    # more than one page
    else:
        min_days = num_pages//2

    # odd means the last day will have three pages
    odd = num_pages % 2 != 0
    
    all_days, start = [], 1
    for x in range(1, min_days + 1):
        # odd and the last day means there should be three pages
        if odd and x == min_days:
            # go to end
            day = list(range(start, num_pages + 1))

        # still pages before end or even
        else:
            day = [start, x * 2]

        start += 2
        all_days.append(day)
        
    solutions.append(all_days)

    
# output results
for sol in solutions:
    print(len(sol))
    for day in sol:
        print(len(day), *day)
            
