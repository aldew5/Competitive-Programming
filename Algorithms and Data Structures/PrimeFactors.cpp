vector<int> primeFactors(int a)  {
    int n = a;

    vector<int> out;
    while (n % 2 == 0)  {
        out.push_back(2);
        n = n/2;
    }

    // n must be odd at this point. So we can skip
    for (int i = 3; i <= sqrt(n); i = i + 2)  {
        // While i divides n, print i and divide n
        while (n % i == 0)  {
            out.push_back(i);
            n = n/i;
        }
    }

    // is a prime number greater than 2
    if (n > 2)
        out.push_back(n);

    return out;
}
