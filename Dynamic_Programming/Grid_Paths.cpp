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
    int n;
    cin >> n;
    vector<vector<bool>> mat(n,vector<bool>(n,false));
    vector<vector<ll>> dp(n, vector<ll>(n, 0));
    for(int i = 0;i<n;i++ ){
        for(int j=0;j<n;j++){
            char x;
            cin >> x;
            mat[i][j] = (x == '*');
        }
    }
    if (!mat[0][0]) dp[0][0]++;;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if (i>0 && !mat[i][j]) dp[i][j]= (dp[i][j] +dp[i-1][j]) % MOD;
            if (j>0 && !mat[i][j]) dp[i][j]= (dp[i][j] + dp[i][j-1]) % MOD;
        }
    }
    cout << dp[n-1][n-1] << endl;
}

int main()
{
    fastio();
    solve();
    return 0;
}