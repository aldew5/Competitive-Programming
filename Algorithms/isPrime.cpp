bool isPrime(int n){
    prime = true;
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
