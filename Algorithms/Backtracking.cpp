bool backtrack(pair<int, int> pos, pair<int, int> dest, int c){
    if (pos == dest){
        ans = c;
        return true;
    }
    else if((pos.ff > 8 || pos.ss > 8) || (pos.ff <0 || pos.ss <0)){
        return false;
    }
    else {
        for (int i = 0; i < moves.size(); i++){
            pos.ff += moves[i].ff;
            pos.ss += moves[i].ss;
            c ++;
            if (visited[pos.ff][pos.ss]) {
                pos.ff -= moves[i].ff;
                pos.ss -= moves[i].ss;
                c --;
                continue;
            }
            else visited[pos.ff][pos.ss] = true;

            if (solve(pos, dest, c)){
                return true;
            }
            else {
                pos.ff -= moves[i].ff;
                pos.ss -= moves[i].ss;
                c --;
            }
        }
    }
    return false;
}
