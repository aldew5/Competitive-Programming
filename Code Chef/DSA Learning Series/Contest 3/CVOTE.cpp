/*
Aldew
PROB: Chef of the Year
CLASSIFICATION:
DIFFICULTY:
*/

#include <bits/stdc++.h>
#define check(x) cout<<(#x)<<": "<<x<<" ";
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int main()
{
    io;
    ll n, m;
    cin >> n >> m;

    map<string, int> votes;
    map<string, int> country;
    map<string, string> p_to_c;

    vector<string> people;
    vector<string> counts;

    string person, c;
    for (int i = 0; i < n; i++){
        cin >> person >> c;
        p_to_c[person] = c;

        people.push_back(person);
        counts.push_back(c);
    }

    // votes
    for (int i = 0; i < m; i++){
        cin >> person;
        votes[person] ++;
        country[p_to_c[person]] ++;
    }

    ll high = 0;
    vector<string> ans;
    for (int i = 0; i < people.size(); i++){
        if (votes[people[i]] > high){
            high = votes[people[i]];
            ans.clear();
            ans.push_back(people[i]);
        }
        else if (votes[people[i]] == high){
            ans.push_back(people[i]);
        }
    }
    sort(ans.begin(), ans.end());

    ll w = 0;
    vector<string> out;
    for (int i = 0; i < counts.size(); i++){
        if (country[counts[i]] > w){
            w = country[counts[i]];
            out.clear();
            out.push_back(counts[i]);
        }
        else if (country[counts[i]] == w) {
            out.push_back(counts[i]);
        }
    }
    sort(out.begin(), out.end());
    cout << out[0] << endl;
    cout << ans[0] << endl;

 	return 0;
}
