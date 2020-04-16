# "Stupid Machine"
# Alec Dewulf
# DSA Learning Series

# Difficulty: Easy
# Concepts: Greedy

"""
The number of tokens being added is just the length of
the list of boxes up to the smallest boxes multiplied
by how many times a token can be added to the minimum
before it's reached capacity.
"""

num_tests = int(input())
ans = []

for t in range(num_tests):
    num_boxes = int(input())
    t_caps = list(map(int, input().split()))

    s = 0
    while num_boxes != 0:
        minimum = min(t_caps[:num_boxes])
        index = t_caps.index(minimum)
        
        s += (num_boxes - index)* minimum
        num_boxes = index
        
    ans.append(s)

for a in ans:
    print(a)
