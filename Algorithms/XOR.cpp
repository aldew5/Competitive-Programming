// computes XOR of two numbers without using the "^" operator

ll XOR(ll x, ll y){
    ll res = 0; // Initialize result
 
    // Assuming 32-bit Integer
    for (int i = 31; i >= 0; i--){
       // Find current bits in x and y
       bool b1 = x & (1 << i);
       bool b2 = y & (1 << i);
 
        // If both are 1 then 0 else xor is same as OR
        bool xoredBit = (b1 & b2) ? 0 : (b1 | b2);
 
        // Update result
        res <<= 1;
        res |= xoredBit;
    }
    return res;
}
