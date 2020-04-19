# "Life, the Universe and Everything
# Alec Dewulf
# DSA Learning Series

# Difficulty: Cakewalk
# Concepts: Basic algorithms

ans = []
while True:
    num = int(input())

    if num != 42:
        ans.append(num)
    else:
        break

for a in ans:
    print(a)
