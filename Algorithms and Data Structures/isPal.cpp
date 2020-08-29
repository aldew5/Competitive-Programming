bool isPal(string s){
    string rev = string(s.rbegin(), s.rend());
    if (rev == s) return true;
    else return false;
}
