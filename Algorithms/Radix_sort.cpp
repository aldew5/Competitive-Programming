
// O(n) sorting
void radix_sort(vector<pair<pair<int, int>, int>> &a){
    int n = a.size();
    {
        vector<int> cnt(n);

        for (auto x: a){
            cnt[x.first.second] ++;
        }
        vector<pair<pair<int, int>, int>> a_new(n);
        vector<int> pos(n);
        pos[0] = 0;
        for (int i = 1; i < n; i++){
            pos[i] = pos[i-1] + cnt[i -1];
        }
        for (auto x : a){
            int i = x.first.second;
            a_new[pos[i]] = x;
            pos[i] ++;
        }
        a = a_new;
    }
    {
        vector<int> cnt(n);
        for (auto x: a){
            cnt[x.first.first] ++;
        }
        //cout << ""
        vector<pair<pair<int, int>, int>> a_new(n);
        vector<int> pos(n);
        pos[0] = 0;
        for (int i = 1; i < n; i++){
            pos[i] = pos[i-1] + cnt[i -1];
        }
        for (auto x : a){
            int i = x.first.first;
            a_new[pos[i]] = x;
            pos[i] ++;
        }
        a = a_new;
    }
}
