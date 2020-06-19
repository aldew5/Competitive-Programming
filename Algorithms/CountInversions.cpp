//Divide and conquer algorithm to count
//inversions in an array

ll CountSplitInversions(int L[], int R[], int nl, int nr){

    sort(L, L + nl);
    sort(R, R + nr);

    ll ans = 0;
    int j = 0, i = 0;

    while (i < nl && j < nr){
        // inversion
        if (L[i] > R[j]){
            ans += nl - i;
            j ++;
        }
        else {
            i ++;
        }
    }
    return ans;
}

ll CountInversions(int arr[], int n){

    if (n == 1) return 0;
    else {
        int R[n-n/2], L[n/2];
        for (int i = 0; i < n; i++){
            if (i < n/2){
                L[i] = arr[i];
            }
            else{
                R[i - n/2] = arr[i];
            }
        }


        ll x = CountInversions(L, n/2);
        ll y = CountInversions(R, n - n/2);
        ll z = CountSplitInversions(L, R, n/2, n- n/2);

        return x + y + z;
    }
}
