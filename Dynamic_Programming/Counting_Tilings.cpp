#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define pb push_back
#define mp make_pair
const ll MOD = 1e9 + 7;
ll dp[1050][2050];

void fastio()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void count_colonne(int n, int curr,int i, int next,vector<int> &next_masks){
// curr et next sont des bitmasks
    if (i==n){
        next_masks.pb(next);
    }
    else{
        if ((curr & 1<<i)==0 && (curr & 1<<(i+1))==0 && i<(n-1)){
            count_colonne(n,curr+(1<<i)+(1<<(i+1)),i+2,next,next_masks);
        }
        if ((curr & 1<<i)==0){
            count_colonne(n,curr+(1<<i),i+1,next+(1<<i),next_masks);
        }
        
        if (curr & 1<<i) {
            count_colonne(n,curr,i+1,next,next_masks);
        }
            
    }

}


int count_ligne(int n, int m, int j, int curr){
    if (j==m){
        int res = curr==0; // si le mask à la colonne m est bien vide ce mask est solution
        return res;
    }
    if (dp[j][curr] != -1){
        return dp[j][curr];
    }
    else{
        vector<int> next_masks;
        count_colonne(n,curr,0,0,next_masks);
        int res = 0;
        for(auto x: next_masks){
            res=((res%MOD) + (count_ligne(n,m,j+1,x)%MOD))%MOD;
        }
        return dp[j][curr]=res;
    }

}

void solve()
{ 
    int n,m;
    cin >> n >> m;
    memset(dp,-1,sizeof(dp));
    cout << count_ligne(n,m,0,0) << endl;
}

int main()
{
    fastio();
    solve();
    return 0;
}