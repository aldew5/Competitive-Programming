int toggleKthBit(int n, int k){
    return (n ^ (1 << (k-1)));
}
