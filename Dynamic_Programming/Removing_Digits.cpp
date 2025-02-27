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
    vector<int> dp(n+1,INT_MAX);
    dp[0]=0;
    for(int i = 1;i<=n;i++){
        string is = to_string(i);

        for(int j = 0;j<size(is);j++){
            int digit = is[j] - '0';
            if (dp[i-digit] != INT_MAX)dp[i] = min(dp[i],dp[i-digit]+1);
        }
   }
    cout << dp[n] << endl;
}

int main()
{
    fastio();
    solve();
    return 0;
}