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


bool rec_fill(int i,int j,vector<vector<char>> &mat,vector<vector<char>> &mat_res){
    int n = mat.size();
    if (i==n){return true;}
    int m = mat[0].size();
    int nexti = j==m-1?i+1:i;
    int nextj = j==m-1?0:j+1;
    char r = j<(m-1)?mat[i][j+1]:'F';
    if (r!=mat[i][j] && r!='F'){
        if ((i==0 || mat_res[i-1][j] != r) && (j==0 || mat_res[i][j-1] != r)){
            mat_res[i][j] = r;
            if (rec_fill(nexti,nextj,mat,mat_res)){
                return true;
            }
        }
    }
    char d = i<(n-1)?mat[i+1][j]:'F';
    if (d!=mat[i][j] && d!='F'){
        if ((i==0 || mat_res[i-1][j] != d) && (j==0 || mat_res[i][j-1] != d)){
            mat_res[i][j] = d;
            if (rec_fill(nexti,nextj,mat,mat_res)){
                return true;
            }
        }
    }
    for(int k = 0;k<4;k++){
        char to_put = ('A'+k);
        if (to_put!=mat[i][j] && to_put!= r && to_put!= d){
            if ((i==0 || mat_res[i-1][j] != to_put) && (j==0 || mat_res[i][j-1] != to_put)){
                mat_res[i][j] = to_put;
                if (rec_fill(nexti,nextj,mat,mat_res)){
                    return true;
                }
            }
        }
    }
    return false;
}

void solve()
{ 
    int n,m;
    cin >> n >> m;
    vector<vector<char>> mat(n,vector<char>(m,'F'));
    vector<vector<char>> mat_res(n,vector<char>(m,'F'));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin >> mat[i][j];
        }
    }
    if (rec_fill(0,0,mat,mat_res)){
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                cout << mat_res[i][j];
                if (j==m-1)cout << endl;
            }
        }
    }
    else{
        cout << "IMPOSSIBLE" << endl;
    }
}

int main()
{
    //fastio();
    solve();
    return 0;
}