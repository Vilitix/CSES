#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define pb push_back
#define mp make_pair
const ll MOD = 1e9 + 7;

void fastio()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

bool inside(int i, int j){
    return (i>=0 && i<8 && j>= 0 && j<8);
}

void change_diag(vector<vector<bool>> &cb, int i, int j,bool turn){
    for(int k = 1;k<8;k++){
        if (inside(i+k,j+k)) cb[i+k][j+k] = turn;
        if (inside(i+k,j)) cb[i+k][j] = turn;
        if (inside(i+k,j-k)) cb[i+k][j-k] = turn;
    }
}

int backtrack(vector<vector<bool>> &cb,int curl){
    int res = 0;
    for(int j =0;j<8;j++){
        if (cb[curl][j]){
            vector<vector<bool>> ncb = cb;
            change_diag(ncb,curl,j,false);
            if (curl !=7) res+= backtrack(ncb,curl+1);
            else{
                res+=1;
            }
        }
    }
    return res;
}

void solve()
{ 
    vector<vector<bool>> cb(8,vector<bool>(8,true));
    for(int i =0;i<8;i++){
        string x;
        cin >> x;
        for(int j=0;j<8;j++){
            if (x[j]=='*'){
                cb[i][j] = false;
            }
        }
    }
    cout << backtrack(cb,0) << endl;
}

int main()
{
    fastio();
    solve();

    return 0;
}