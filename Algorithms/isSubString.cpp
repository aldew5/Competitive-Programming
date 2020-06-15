/*
Brute force O(n^2) algorithm to check for substrings.
*/

bool isSubString(string a, string b){
    bool good = false;
    for (int i = 0; i < a.size(); i++){
        if (a[i] == b[0]){
            good = true;
            for (int j = i, c = 0; j < i + b.size(); j++, c++){
                if (a[j] != b[c]){
                    good = false;
                    break;
                }
            }
        }
        if (good) break;
    }

    if (good) return true;
    else return false;
    
}
