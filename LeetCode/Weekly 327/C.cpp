class Solution {
public:
    bool isItPossible(string word1, string word2) {
        map<int, int> w1;
        map<int, int> w2;
    
        for (int i = 0; i < word1.size(); i++){
            w1[word1[i]] ++;
        }
        for (int i = 0; i < word2.size(); i++){
            w2[word2[i]] ++;
        }
        
        
        string alph = "abcdefghijklmnopqrstuvwxyz";
        int d1 = 0; int d2 = 0;
        for (int i = 0; i < alph.size(); i++){
           if (w1[alph[i]] > 0){
               d1 ++;
           }
            
            if (w2[alph[i]] > 0){
                d2 ++;
            }
        }
        cout << d1 << " "<< d2 << endl;
        
        
        
        for (int i = 0; i < alph.size(); i++){
            for (int j = 0; j < alph.size(); j++){
                if (w1[alph[i]] == 0 || w2[alph[j]] == 0){
                    continue;
                }
                
                int delta_a = 0;
                delta_a -= (w1[alph[i]] == 1);
                w1[alph[i]] --;
                delta_a += (w1[alph[j]] == 0);
                w1[alph[i]] ++;
                
                int delta_b = 0;
                delta_b -= (w2[alph[j]] == 1);
                w2[alph[j]] --;
                delta_b += (w2[alph[i]] == 0);
                w2[alph[j]] ++;
                
                
                cout << alph[i] << " " << alph[j] << " " << delta_a << " " << delta_b << endl;
                
                if (d1 + delta_a == d2 + delta_b){
                    cout << alph[i] << " " << alph[j] << endl;
                    cout << delta_a << " " << delta_b << endl;
                    cout << d1 << " " << d2 << endl;
                    return true;
                }
            }
        }
        return false;
    }
    
};
