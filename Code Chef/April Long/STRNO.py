# "Strange Number"
# Alec Dewulf
# April Long 2020

# Difficulty: Easy
# Prerequisities: Number Theory


"""
OVERVIEW

This solution is based on the idea that the number of prime factors (k) must be less
than the total prime factors (max_k). The number of factors can be calculated by
adding one to each exponent in a number's prime factorization and then multiplying
those exponents.


HELPER FUNCTIONS

Is_prime returns True if none of the numbers less than the square root of n
divide it and False otherwise.

get_prime factors takes in n and k and returns the length of the list of n's prime
factorization.

Example:
get_prime_factors(100, 2)

returns: 4 --> len([2, 2, 5, 5])

k is used as a limit. If at any time the length of prime factors reaches k, then that k is
valid and there is no need to collect more of the prime factors.


MAIN SOLUTION

After getting inputs, max_k is assigned to the value of the function call get_prime_factors(x, k).
This is the max value k can take on because there need to be at least k things that multiply to be x.
The most amount of things you can multiply to get x is all the numbers of its prime factorization.

Example:
x = 100
k = 4

100 = 5x5x2x2

Therefore you can have a k up to four and have 100 work as a value of x.
For example the number: 2^4 x 3^4 x 5^1 x 7^1 will have 100 factors
((4+1)*(4+1)*(1+1)*(1+1)) and 4 prime factors (2, 3, 5, 7).
No greater amount of prime factors are possible because there are no five
things that multiply to be 100 (You can't use 1 or break down the prime
factorization any more)

"""

def is_prime(n):
    if n < 2:
        return False
    return all(n % i for i in range(2, int(math.sqrt(n)) + 1))

def get_prime_factors(n, k):
    prime_factors = []
    d = 2
    while d * d <= n:
        while n % d == 0:
            n //= d
            prime_factors.append(d)

            if len(prime_factors) == k:
                return k
        d += 1
        
    # avoid 1 as a factor
    if n > 1:
        assert d <= n
        prime_factors.append(n)

        if len(prime_factors) == k:
            return k
        
    return len(prime_factors)


test_cases = int(input())
answers = []
for n in range(test_cases):
    x, k = map(int, input().split())

    max_k = get_prime_factors(x, k)
    # no number with 1 factor
    if x == 1:
        answers.append(0)
    elif k <= max_k:
        answers.append(1)
    else:
        answers.append(0)
             
# return results
for a in answers:
    print(a)
