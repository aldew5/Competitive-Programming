#"Lift Requests"
# Alec Dewulf
# April Cookoff 2020

# Difficulty: Cakewalk
# Concepts: Implementation

T = int(input())
ans = []
for _ in range(T):
    num_floors, num_requests = map(int, input().split())

    pos, total = 0, 0
    for q in range(num_requests):
        source, dest = map(int, input().split())

        # dist to the source from pos
        dist = abs(source - pos)
        pos = source

        # dist to dest from pos
        dist += abs(dest - pos)
        pos = dest
        
        total += dist

    print(total)
        
