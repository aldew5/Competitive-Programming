# "Chef and Numbers"
# Alec Dewulf
# Difficulty: Cakewalk

T = int(input())

for _ in range(T):
    n = int(input())
    arr = map(int, input().split())

    d = {}
    prev_x = None
    # create a dictionary with alues for each type
    for x in arr:
        add = False
        
        # new value
        if x not in d:
            d[x] = 1
            add = True  
        # not beside
        elif x != prev_x:
            d[x] +=1
            add = True

        # need to skip adjacent
        if add:
            prev_x = x
        # can add
        else:
            prev_x = None

    # find the lowest value for the highest count
    ans, max_value = None, None
    for k in d:
        if max_value == None or d[k] > max_value:
            max_value = d[k]
            ans = k
        elif d[k] == max_value and k < ans:
            ans = k

    print(ans)
