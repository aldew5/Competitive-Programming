# "Penality Shoot-Out II"
# Alec Dewulf
# DSA Learning Series

# Difficulty: Cakewalk
# Concepts: Basic algorithms

"""
Simply check whether it's impossible for a team to win after each shot.
"""


import math

num_tests = int(input())
ans = []

for t in range(num_tests):
    num_shots = int(input())
    shots = input()

    add = False

    a_points, b_points = 0, 0
    x = 0
    while x < len(shots):
        a_points += int(shots[x])
        x += 1
        
        if a_points > b_points + num_shots\
           or b_points > a_points + num_shots - 1:
            ans.append(x)
            add = True
            break

        b_points += int(shots[x])
        x +=1
        num_shots -= 1
        
        if b_points > a_points + num_shots\
           or a_points > b_points + num_shots:
            ans.append(x)
            add = True
            break

    # it took every shot
    if not add:
        ans.append(len(shots))

for a in ans:
    print(a)
            
