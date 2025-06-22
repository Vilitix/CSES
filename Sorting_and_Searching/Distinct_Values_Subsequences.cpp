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
    vector<ll> tab(n);
    map<ll,ll> freq;
    for(int i = 0;i<n;i++){
        cin >> tab[i],freq[tab[i]]++;
    }
    ll res = 1;
    for(auto [a,b]:freq){
        res= (res*1ll*(b+1))%MOD;
    }
    res-=1ll; // subarray vide impossible
    
    cout << res << endl;
}

int main()
{
    fastio();
    solve();
    return 0;
}