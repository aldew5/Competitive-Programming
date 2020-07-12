/*
ID: alec3
LANG: C++14
PROG: sprime
CLASSIFICATION: brute force
*/

#include <bits/stdc++.h>
#define check(x) cout<<(#x)<<": "<<x<<" ";
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


typedef long long ll;
typedef unsigned long long ull;

using namespace std;

vector<int> primes;
void SieveOfEratosthenes(int a, int n) {

    vector<int> prime(n+1);
    for (int i = 0; i < prime.size(); i++){
        prime[i] = true;
    }
    //memset(prime, true, n+1);

    for (int p=2; p*p<=n; p++) {
        if (prime[p] == true) {
            for (int i=p*p; i<=n; i += p)
                prime[i] = false;
        }
    }

    // Print all prime numbers
    for (int p=a; p<=n; p++)
       if (prime[p])
          primes.push_back(p);
}

bool isPrime(int n){
    bool prime = true;
    if (n == 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    for (int i = 3; i < sqrt(n) + 1; i+= 2){
        if (n % i == 0){
            prime = false;
            break;
        }
    }
    return prime;
}

long long fast_power(long long base, long long power) {
    long long result = 1;
    while(power > 0) {

        if(power % 2 == 1) { // Can also use (power & 1) to make code even faster
            result = (result*base);
        }
        base = (base * base);
        power = power / 2; // Can also use power >>= 1; to make code even faster
    }
    return result;
}


int main() {

	ifstream fin("sprime.in");
	ofstream fout("sprime.out");

    int n;
    fin >> n;

    SieveOfEratosthenes(pow(10, n-1), pow(10, n) -1);

    string s, sub;
    int num, p;
    bool good;
    for (int i = 0; i < primes.size(); i++){
        s = to_string(primes[i]);

        good = true;
        for (int j = 1; j < s.size(); j++){
            num = 0;
            sub = s.substr(0, j);

            // pow function doesn't fucking work
            for (int k = 0; k < sub.size(); k++){
                p = fast_power(10, sub.size() -(k + 1));
                if (k != sub.size() - 1) num += (sub[k] - '0') * p;
                else num += (sub[k] - '0');
            }

             if (!isPrime(num)) {
                    good = false;
                    break;
                }

        }
        if (good) fout << s << endl;

    }









    return 0;

}
