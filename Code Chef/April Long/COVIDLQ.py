# "COVID Pandemic and Long Queue
# Alec Dewulf
# April Long 2020

# Difficulty: Cakewalk
# Concepts: Basic algorithmic design

"""
EXPLANATION

This problem consists of a simple check to determine whether the five
spots before and after a person are empty. Disregard the spots before
the first person.
"""

number_tests = int(input())
tests = []

for x in range(number_tests):
    
    num_spots = int(input())
    spots = input().split()


    y, feet_between = 0, 1
    start, safe = False, True
    while y < num_spots:
        if spots[y] == '1':
            # discount the starting zeros
            if not start:
                start = True
            # too close
            elif start and feet_between < 6:
                safe = False
                feet_between = 1
                break
            # safe
            elif start and feet_between >= 6:
                safe = True

            feet_between = 1
                    
        elif spots[y] == '0':
            feet_between += 1
        
        y += 1
            
    if safe:
        tests.append("YES")
    else:
        tests.append('NO')


for test in tests:
    print(test)
        
