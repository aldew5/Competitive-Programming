# "Compilers and Parsers"
# Alec Dewulf
# DSA Learning Series

# Difficulty: Easy
# Concepts: Ad-hoc


T = int(input())
ans = []

for _ in range(T):
    code = input()

    num_left, num_right = 0,0

    prefix = 0

    for x in range(len(code)):
        if code[x] == '<':
            num_left += 1
        elif code[x] == '>':
            num_right += 1

        if num_left == num_right:
            # + 1 is because of zero index
            prefix = x + 1
        if num_right > num_left:
            break
                
    ans.append(prefix)

for a in ans:
    print(a)
