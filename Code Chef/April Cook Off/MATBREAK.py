# "Matrix Decomposition"
# Alec Dewulf
# April Cook Off 2020

# Difficulty: Simple
# Concepts: Fast exponentiation, implementation

"""
This problem required the solver to caculate exponentials very quickly.
I did that by computing everything mod so the numbers remained small.
A more efficient exponent function could have also been used.
"""

T = int(input())
mod = 10**9 + 7

for _ in range(T):
    num_rows, value = map(int, input().split())
    ans = 0

    for i in range(1, num_rows + 1):
        # update the answer and compute it mod to save time
        ans += pow(value, 2*i-1, mod)
        ans %= mod
        
        # update the value of the cells
        value = pow(value, 2*i, mod)
        
    print(ans)
        

