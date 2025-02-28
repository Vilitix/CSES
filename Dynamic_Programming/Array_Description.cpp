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

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> tab(n);
    ll dp[n][m+1];
    memset(dp,0,sizeof(dp));
    for (int i = 0; i < n; i++)
        cin >> tab[i];
    if (tab[0] == 0){
        for(int i = 1;i<=m;i++){
            dp[0][i] = 1;
        }
    }
    else{
        dp[0][tab[0]] = 1;
    }
    
    for(int i=1;i<n;i++){
        if (tab[i] != 0){
            dp[i][tab[i]] = (dp[i][tab[i]] + dp[i-1][tab[i]] + dp[i-1][tab[i]-1] + dp[i-1][tab[i]+1])%MOD ;
        }
        else{
            for(int j = 1;j<=m;j++){
                dp[i][j]= (dp[i][j]+ dp[i-1][j])%MOD;
                if (j!= 0) dp[i][j] = (dp[i][j] + dp[i-1][j-1])%MOD;
                if (j!= m) dp[i][j] = (dp[i][j]+ dp[i-1][j+1])%MOD;
            }
        }
    }
    ll res = 0;
    for(int i = 0;i<=m;i++){
        res= (res + dp[n-1][i]) % MOD;
    }
    cout << res << endl;
}

int main()
{
    fastio();
    solve();
    return 0;
}