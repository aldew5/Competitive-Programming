using namespace std;
/*
Arguments are vectors with each index representing an integer and its
place in a number. Designed to multiply integers too big to be
stored by an unsigned long long.
*/

vector<int> LongMulti(vector<int> x, vector<int> y){
    vector<vector<int> > rows;
    vector<int> ans = {0};

    vector<int> row;
    int carry = 0, zero_count = 0, longest = 0;
    bool needCarry;

    for (int j = y.size() -1; j >= 0; j--){
        carry = 0;

        for (int i = 0; i < zero_count; i++){
            row.push_back(0);
        }

        for (int i = x.size() -1; i >= 0; i--){
            needCarry = false;
            if (x[i] * y[j] + carry >= 10){
                row.push_back((x[i] * y[j] + carry) % 10);
                carry = (x[i] * y[j] + carry) / 10;
                needCarry = true;
            }
            else {
                row.push_back(x[i] * y[j] + carry);
                carry = 0;
            }
        }

        if (needCarry) row.push_back(carry);

        if (row.size() > longest) longest = row.size();

        zero_count ++;
        rows.push_back(row);

        row.clear();
    }


    int index = 0;
    // loop through the tens places
    for (int i = 0; i < longest; i++){
        // loop through rows
        carry = 0;
        for (int j = 0; j < rows.size(); j++){
            if (i < rows[j].size()){
                if (ans[index] + rows[j][i] < 10){
                    ans[index] += rows[j][i];
                }
                else {
                    carry += 1;
                    ans[index] += (rows[j][i]) -10;
                }
            }
        }

        index ++;
        ans.push_back(carry);
    }

    if (ans[ans.size() -1] == 0) ans.erase(ans.begin() + ans.size() -1);
    reverse(ans.begin(), ans.end());
    
    return ans;
}
