# "Reverse the Number"
# Alec Dewulf
# DSA Learning Series

# Difficulty: Cakewalk
# Concepts: Basics algorithms

ans = []
num_tests = int(input())
for n in range(num_tests):
    number = list(input())

    new_num = ''
    x = -1
    while x >= (len(number)* -1):
        new_num += str(number[x])

        x -= 1

    ans.append(int(new_num))

for n in ans:
    print(n)
