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



// bitshifts
int pwr(int a,ll b) {
	int ans = 1;
	while(b) {
		if(b & 1) ans = (ans * 1LL * a);
		a = (a * 1LL * a);
		b >>= 1;
	}
    return ans;
}

