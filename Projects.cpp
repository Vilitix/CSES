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
    vector<int> s(n),e(n),r(n); 
    set<int> se;
    for(int i = 0;i<n;i++){
        cin >> s[i] >> e[i] >> r[i];
        e[i]++;
        se.insert(s[i]);
        se.insert(e[i]);
    }
    // get index
    map<int,int> index;
    int j = 0;
    for(auto x:se){
        index[x] = j++;
    }
    vector<ll> dp(j,0);
    vector<vector<pair<int,int>>> detailsdp(j);
    for(int i = 0;i<n;i++){
        detailsdp[index[e[i]]].pb(mp(index[s[i]],r[i]));
    }
    for(int i = 0;i<j;i++){
        if (i>0)dp[i] = dp[i-1];
        for(auto v:detailsdp[i]){
            dp[i] = max(dp[i],dp[v.first]+v.second);
        }
    }
    cout << dp[j-1] << endl;


}

int main()
{
    fastio();
    solve();
    return 0;
}