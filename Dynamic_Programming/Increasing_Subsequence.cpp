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
    vector<int> tab(n) ;
    for(int i=0;i<n;i++) cin>> tab[i];
    vector<int> dp(1,tab[0]);
    for(int i = 1;i<n;i++){
        auto x = lower_bound(dp.begin(),dp.end(),tab[i]);
        if (x == dp.end()){
            dp.pb(tab[i]);
        }
        else{
            *x = tab[i];
        }
    }
    cout << size(dp) << endl;
}

int main()
{
    fastio();
    solve();
    return 0;
}